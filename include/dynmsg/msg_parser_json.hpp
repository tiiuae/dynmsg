// Copyright 2020 Open Source Robotics Foundation, Inc.
// Copyright 2021 Christophe Bedard
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DYNMSG__MSG_PARSER_JSON_HPP_
#define DYNMSG__MSG_PARSER_JSON_HPP_

#include <string>

#include "rcutils/allocator.h"

#include "typesupport.hpp"

namespace dynmsg
{

namespace c
{

/// Parse a json representation of a message into a ROS message and store it in a raw bytes buffer.
/**
 * The introspection information is used to convert the json representation into the correct binary
 * representation for the given ROS message.
 *
 * It is an error for the json representation to contain a field that is not in the ROS message.
 * It is not an error for a field of the ROS message to not be specified in the json
 * representation; that field will be left uninitialised.
 */
RosMessage json_to_rosmsg(const InterfaceTypeName & interface_type, const std::string & json_str);

/// Version of json_to_rosmsg() with TypeInfo provided directly, and an allocator.
/**
 * \see dynmsg::c::json_to_rosmsg()
 */
RosMessage json_and_typeinfo_to_rosmsg(
  const TypeInfo * type_info,
  const std::string & json_str,
  rcutils_allocator_t * allocator);

}  // namespace c

namespace cpp
{

/// C++ version of dynmsg::c::json_to_rosmsg().
/**
 * \see dynmsg::c::json_to_rosmsg()
 */
RosMessage_Cpp json_to_rosmsg(
  const InterfaceTypeName & interface_type,
  const std::string & json_str);

/// C++ version of dynmsg::c::json_and_typeinfo_to_rosmsg().
/**
 * \see dynmsg::c::json_and_typeinfo_to_rosmsg()
 */
RosMessage_Cpp json_and_typeinfo_to_rosmsg(
  const TypeInfo_Cpp * type_info,
  const std::string & json_str,
  rcutils_allocator_t * allocator);

/// Version of dynmsg::cpp::json_and_typeinfo_to_rosmsg() using an existing empty message.
/**
 * Takes a pointer to an existing empty message.
 *
 * \see dynmsg::cpp::json_and_typeinfo_to_rosmsg()
 */
void json_and_typeinfo_to_rosmsg(
  const TypeInfo_Cpp * type_info,
  const std::string & json_str,
  void * ros_message);

}  // namespace cpp

}  // namespace dynmsg

#endif  // DYNMSG__MSG_PARSER_JSON_HPP_

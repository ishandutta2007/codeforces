#!/usr/bin/env ruby

a = gets.split.map(&:to_i).sort

ans = 0
ans = (a[4] == a[5] ? 1 : 2) if a[0] == a[3]
ans = (a[0] == a[5] ? 1 : 2) if a[1] == a[4]
ans = (a[0] == a[1] ? 1 : 2) if a[2] == a[5]
puts case ans
when 0
  'Alien'
when 1
  'Elephant'
when 2
  'Bear'
end
#!/usr/bin/env ruby

n = gets.to_i
h = gets.split.map(&:to_i)
sol = []
100.times do
  x = h.map{|x| x * 10 + rand(10)}.map.with_index(1).sort.map(&:last)
  sol << x if !sol.include?(x)
  break if sol.size == 3
end

if sol.size == 3
  puts 'YES'
  puts sol.map{|x| x.map(&:to_s).join(' ')}
else
  puts 'NO'
end
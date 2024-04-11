n = gets.to_i
l = gets.split.map { |x| x.to_i }

l.sort!
max = l.pop
sum = l.reduce(:+)

puts [max - sum + 1, 0].max
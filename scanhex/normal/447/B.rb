s = gets.chomp
k = gets.to_i
w = gets.split.map {|i| i.to_i}
m = w.max
sum = 0
s.scan(/./).each_with_index {|i, x| sum += w[i.ord - 'a'.ord] * (x + 1)}
for i in 1..k
  sum += m * (i + s.length)
end
puts sum
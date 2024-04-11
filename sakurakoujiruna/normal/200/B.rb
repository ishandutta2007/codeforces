n = gets.to_i
sum = gets.split.map { |x| x.to_i }.reduce(:+)

puts '%.6f' % (sum.to_f / n)
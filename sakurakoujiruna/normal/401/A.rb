n, x = gets.split.map { |x| x.to_i }
sum = gets.split.map { |x| x.to_i }.reduce(:+).abs
puts (sum + x - 1) / x
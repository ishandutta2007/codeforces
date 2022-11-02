a, b, c = gets.split.map { |x| x.to_i }
mul = ((a * b * c) ** 0.5).round
a, b, c = mul / a, mul / b, mul / c

puts (a + b + c) * 4
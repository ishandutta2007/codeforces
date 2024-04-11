n, a, b = gets.split.map { |x| x.to_i }
a += 100 * n + b
puts (a - 1) % n + 1
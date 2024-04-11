k, n, w = gets.split.map { |x| x.to_i }
n = w * (w + 1) / 2 * k - n
n = 0 if n < 0
puts n
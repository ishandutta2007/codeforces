n, m = gets.split.map { |x| x.to_i }

cb = n % m
cs = m - cb

min = cs * (n / m - 1) * (n / m) / 2 + cb * (n / m) * (n / m + 1) / 2
max = (n - m) * (n - m + 1) / 2

puts [min, max].join ' '
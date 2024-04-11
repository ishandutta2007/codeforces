c, d = gets.split.map {|x| Integer x}
n, m = gets.split.map {|x| Integer x}
k = Integer gets
a = n * m - k
puts [[a / n * c + (a % n) * d, a * d, (a + n - 1) / n * c].min, 0].max
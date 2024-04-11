def gcd a, b
	return a if b == 0
	gcd b, a % b
end

x, y, a, b = gets.split.map { |x| x.to_i }
l = x / gcd(x, y) * y
puts b / l - (a - 1) / l
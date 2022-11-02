def gcd a, b
	return a if b == 0
	gcd b, a % b
end

y, w = gets.split.map { |x| x.to_i }

a = 6 - [y, w].max + 1
b = 6
g = gcd a, b
puts [a / g, b / g].join '/'
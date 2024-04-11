def gcd a, b
	return a if b == 0
	gcd b, a % b
end

n = gets.to_i
a = gets.split.map { |x| x.to_i }

g = a[0]
a.each do |x|
	g = gcd g, x
end
puts g * n
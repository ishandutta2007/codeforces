d, h, v, e = gets.split.map { |x| x.to_i }
s = (d / 2.0) ** 2 * Math::PI

if v / s > e
	puts "YES"
	ans = h / (v / s - e)
	puts "%.12f" % ans
else
	puts "NO"
end
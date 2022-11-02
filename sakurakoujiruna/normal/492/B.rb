n, l = gets.split.map { |x| x.to_i }
a = gets.split.map { |x| x.to_i }
a.sort!

f = [a[0] * 2, (l - a[-1]) * 2]
1.upto(n - 1) do |i|
	f << (a[i] - a[i - 1])
end

ans = f.max / 2.0
puts '%.12f' % ans
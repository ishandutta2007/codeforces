n = gets.to_i
d = n.to_s.length

ans = n * d
1.upto(d - 1) do |i|
	ans -= (d - i) * 9 * 10 ** (i - 1)
end
puts ans
def s x
	x.to_s.chars.map { |c| c.to_i }.reduce(:+)
end

a, b, c = gets.split.map { |x| x.to_i }

ans = []
1.upto(100) do |i|
	x = b * i ** a + c
	if x > 0 and x < 1e9.to_i and s(x) == i
		ans << x
	end
end

puts ans.size
puts ans.sort.join ' '
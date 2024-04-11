n = gets.to_i
a = gets.split.map { |x| x.to_i }

ans = 0
1.upto(5) do |i|
	ans += 1 if (i + a.reduce(:+) - 1) % (n + 1) != 0
end
puts ans
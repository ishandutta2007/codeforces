n, a, b = gets.split.map { |x| x.to_i }

ans = 0
1.upto(n) do |i|
	ans += 1 if i - 1 >= a and n - i <= b
end
puts ans
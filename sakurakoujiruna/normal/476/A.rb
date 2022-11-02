n, m = gets.split.map { |x| x.to_i }
min = (n + 1) / 2
max = n

ans = -1
min.upto(max) do |i|
	if i % m == 0
		ans = i
		break
	end
end

puts ans
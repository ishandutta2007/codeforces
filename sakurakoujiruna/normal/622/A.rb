n = gets.to_i

left = 0
right = 1e8.to_i
while left + 1 < right
	mid = (left + right) / 2
	if mid * (mid + 1) / 2 < n
		left = mid
	else
		right = mid
	end
end

puts n - left * (left + 1) / 2
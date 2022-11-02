n, k = gets.split.map { |x| x.to_i }
evens = n / 2
odds = n - evens
offset = 0
if k > odds
	k -= odds
	offset = 1
end

puts k * 2 - 1 + offset
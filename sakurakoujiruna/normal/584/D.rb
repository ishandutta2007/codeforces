def check_prime n
	return false if n == 1

	(2...n).each do |i|
		if i * i > n then
			break
		end
		if n % i == 0 then
			return false
		end
	end
	true
end

n = gets.to_i

if n == 3 then
	puts 1
	puts 3
elsif n == 5 then
	puts 2
	print 2, ' ', 3, ?\n
else
	puts 3
	print 3, ' '

	(2...n).each do |i|
		if check_prime(i) && check_prime(n - 3 - i) then
			print i, ' ', n - 3 - i, ?\n
			break
		end
	end
end
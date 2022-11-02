# require 'prime'

n = gets.to_i
f = gets.split.map { |x| x.to_i }

# p = Prime.first(700000)
is_prime = Array.new(1000001, true)
is_prime[0] = is_prime[1] = false
2.upto(1000001) do |i|
	if is_prime[i]
		j = i * 2
		while j < 1000001
			is_prime[j] = false
			j += i
		end
	end
end

f.each do |x|
	t = (x ** 0.5).round
	if t ** 2 == x and is_prime[t]
		puts 'YES'
	else
		puts 'NO'
	end
end
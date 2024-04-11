prime = Array.new(1300000, true)

prime[0] = prime[1] = false
2.upto(1300000) do |i|
	if prime[i]
		t = i * 2
		while t < 1300000
			prime[t] = false
			t += i
		end
	end
end

ans = []
n = gets.to_i
2.upto(1300000) do |i|
	if prime[i]
		if n > 0
			n -= 1
			ans << i
		end
	end
end

puts ans.join ' '
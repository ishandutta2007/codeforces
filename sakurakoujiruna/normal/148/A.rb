def gcd a, b
	return a if b == 0
	gcd b, a % b
end
def lcm a, b
	a / gcd(a, b) * b
end

f = []
4.times do
	f << gets.to_i
end
n = gets.to_i

ans = n
1.upto(16) do |k|
	cnt = 0
	gap = 1
	4.times do |i|
		if k[i] == 1
			cnt += 1
			gap = lcm f[i], gap
		end
	end
	if cnt.odd?
		ans += n / gap
	else
		ans -= n / gap
	end
end

puts ans
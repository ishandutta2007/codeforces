n, k = gets.split.map { |x| x.to_i }
c = gets.split.map { |x| x.to_i }
id = gets.split.map { |x| x.to_i }

cap = Array.new n
id.each do |x|
	cap[x - 1] = true
end

sc = 0
sc2 = 0
n.times do |i|
	if cap[i]
		sc += c[i]
		sc2 += c[i] ** 2
	end
end

sum = 0
ans = (sc ** 2 - sc2) / 2
n.times do |i|
	sum += c[i] if !cap[i]
end
n.times do |i|
	ans += c[i] * sum if cap[i]
end

n.times do |i|
	if !cap[i - 1] and !cap[i]
		ans += c[i - 1] * c[i]
	end
end

puts ans
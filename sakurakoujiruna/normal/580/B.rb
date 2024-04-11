n, d = gets.split.map { |s| s.to_i }

f = [[0, 0]]
n.times do
	t = gets.split.map { |s| s.to_i }
	f << t
end
f.sort!

sum = f.map { |item| item[1] }
1.upto(n) do |i|
	sum[i] += sum[i - 1]
end

ans = 0
rp = 1
1.upto(n) do |i|
	rp += 1 while rp < n && f[i][0] + d > f[rp + 1][0]
	ans = [ans, sum[rp] - sum[i - 1]].max
end
puts ans
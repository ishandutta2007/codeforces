n = gets.to_i

a = gets.split.map { |x| x.to_i }
a = [0] + a + [0]

m = gets.to_i
m.times do
	x, y = gets.split.map { |x| x.to_i }
	a[x - 1] += y - 1
	a[x + 1] += a[x] - y
	a[x] = 0
end

1.upto(n) do |i|
	puts a[i]
end
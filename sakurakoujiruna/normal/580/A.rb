def read_int
	c = 0
	while c < 48 || c > 57 do
		c = $stdin.readbyte
	end
	ret = 0
	while c >= 48 && c <= 57 do
		ret = (ret << 3) + (ret << 1) + c - 48
		c = $stdin.readbyte
	end

	ret
end

n = gets.to_i
# a = gets.split.map { |s| s.to_i }
a = []
n.times do 
	a << read_int
end

tmp = 1
ans = 1
(1...n).each do |i|
	if a[i] < a[i - 1]
		tmp = 1
	else
		tmp = tmp + 1
		ans = [ans, tmp].max
	end
end

puts ans
y, k, n = gets.split.map { |x| x.to_i }

x = (y / k + 1) * k - y
ans = []
while x + y <= n
	ans << x
	x += k
end
if ans.size > 0
	puts ans.join ' '
else
	puts -1
end
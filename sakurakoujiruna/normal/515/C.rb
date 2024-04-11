Split = [[], [],
	[2], [3], [3, 2, 2], [5],
	[5, 3], [7], [7, 2, 2, 2], [7, 3, 3, 2]]

n = gets.to_i
s = gets
ans = []
s.each_char do |c|
	ans += Split[c.to_i]
end
ans.sort!.reverse!
puts ans.join
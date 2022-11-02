a, m = gets.split.map { |x| x.to_i }
a = a % m

vis = Array.new m

loop do
	if a == 0
		puts 'Yes'
		break
	elsif vis[a]
		puts 'No'
		break
	else
		vis[a] = true
		a = 2 * a % m
	end
end
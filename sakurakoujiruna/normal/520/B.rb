n, m = gets.split.map { |x| x.to_i }

N = 100000
vis = Array.new(N)
vis[n] = 0

queue = [n]
while !queue.empty?
	x = queue.pop
	if x > 0 and !vis[x - 1]
		vis[x - 1] = vis[x] + 1
		queue.unshift(x - 1)
	end
	if x * 2 < N and !vis[x * 2]
		vis[x * 2] = vis[x] + 1
		queue.unshift(x * 2)
	end
end
puts vis[m]
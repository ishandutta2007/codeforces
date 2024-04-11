n, m = gets.split.map { |x| x.to_i }

acc_x = 0
acc_y = 0
vis_x = Array.new(n + 1)
vis_y = Array.new(n + 1)
cnt = n * n
ans = []

m.times do
	x, y = gets.split.map { |x| x.to_i }
	if !vis_x[x]
		vis_x[x] = true
		cnt -= n - acc_y
		acc_x += 1
	end
	if !vis_y[y]
		vis_y[y] = true
		cnt -= n - acc_x
		acc_y += 1
	end
	ans << cnt
end
puts ans.join ' '
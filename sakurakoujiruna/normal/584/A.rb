n, t = gets.split.map { |s| s.to_i }

if n == 1 && t == 10 then
	puts -1
elsif n == 1 then
	puts t
elsif t == 10 then
	print 1
	(n - 1).times do
		print 0
	end
	print ?\n
else 
	tmp = 10 % t
	print 1
	(n - 2).times do
		print 0
		tmp = tmp * 10 % t
	end
	puts t - tmp
end
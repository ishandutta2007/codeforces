a, b, n = gets.split.map { |x| x.to_i }

begin
	10.times do |i|
		if (a * 10 + i) % b == 0
			raise i.to_s
		end
	end
rescue Exception => x
	puts a.to_s + x.message + '0' * (n - 1)
else
	puts -1
end
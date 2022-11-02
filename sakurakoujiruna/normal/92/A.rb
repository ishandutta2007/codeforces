n, m = gets.split.map { |x| x.to_i }

begin
	loop do
		1.upto(n) do |i|
			if m >= i
				m -= i
			else
				raise m.to_s
			end
		end
	end
rescue Exception => x
	puts x.message
end
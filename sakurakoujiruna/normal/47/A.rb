n = gets.to_i

begin
	100.times do |i|
		raise if i * (i + 1) / 2 == n
	end
rescue
	puts 'YES'
else
	puts 'NO'
end
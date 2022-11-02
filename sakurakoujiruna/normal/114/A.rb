k = gets.to_i
l = gets.to_i
begin
	40.times do |i|
		raise (i - 1).to_s if k ** i == l
	end
rescue Exception => x
	puts 'YES'
	puts x.message
else
	puts 'NO'
end
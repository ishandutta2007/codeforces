n = gets.to_i
sum = [0, 0, 0]
n.times do
	f = gets.split.map { |x| x.to_i }
	3.times do |i|
		sum[i] += f[i]
	end
end

if sum.count(0) == 3
	puts 'YES'
else
	puts 'NO'
end
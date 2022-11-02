n = gets.to_i
a = gets.split.map { |x| x.to_i }
max = 0
1.upto(1000) do |i|
	max = [max, a.count(i)].max
end

if max <= (n + 1) / 2
	puts 'YES'
else
	puts 'NO'
end
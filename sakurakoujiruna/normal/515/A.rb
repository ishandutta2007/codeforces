a, b, s = gets.split.map { |x| x.to_i }
if a.abs + b.abs <= s and (s - a - b).even?
	puts 'Yes'
else
	puts 'No'
end
n = gets.to_i
a = (0...n).map {gets.split.map {|i| i.to_i}}
if a.sort_by { |e| e[0] } == a.sort_by { |e| e[1] }
	puts 'Poor Alex'
else
	puts 'Happy Alex'
end
n = gets.to_i

dom = []
n.times do
	dom << gets.split.map { |x| x.to_i }
end

can_swap = false
dom.each do |d|
	if (d[0] + d[1]).odd?
		can_swap = true
	end
end

su = dom.map { |x| x[0] }.reduce(:+)
sd = dom.map { |x| x[1] }.reduce(:+)

if (su + sd).odd? or (su.odd? and !can_swap)
	puts -1
elsif su.even?
	puts 0
else
	puts 1
end
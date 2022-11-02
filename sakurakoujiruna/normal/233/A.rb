n = gets.to_i

if n.odd?
	puts -1
else
	p = Array.new(n) { |i, v| v = i + 1 }
	(n / 2).times do |i|
		p[i * 2], p[i * 2 + 1] = p[i * 2 + 1], p[i * 2]
	end
	puts p.join ' '
end
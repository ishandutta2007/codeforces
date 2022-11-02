n = gets.to_i

p = Array.new(n) { |i, v| v = i + 1 }

(n - 1).downto(1) do |i|
	p[i - 1], p[i] = p[i], p[i - 1]
end
puts p.join ' '
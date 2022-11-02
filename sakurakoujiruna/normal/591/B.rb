class Solver
	def main
		n, m = gets.split.map { |s| s.to_i }
		str = gets
		
		pos = Array.new(128) { |id, v| v = id }
		to = Array.new(128) { |id, v| v = id }
		m.times do
			a, b = gets.split.map { |c| c.ord }
			to[pos[a]], to[pos[b]] = to[pos[b]], to[pos[a]]
			pos[a], pos[b] = pos[b], pos[a]
		end

		n.times do |i|
			print to[str[i].ord].chr
		end
		print ?\n

	end
end

Solver.new.main
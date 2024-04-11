class Solver
	def main
		x, y = gets.split.map { |s| s.to_i }
		if x < y then
			puts -1
		else
			tmp = (x - y) / (2 * y)
			puts (x + y).to_f / (2 * tmp + 2)
		end
	end
end

Solver.new.main
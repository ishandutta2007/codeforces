class Solver
	def main
		d1, d2, d3 = gets.split.map { |x| x.to_i }
		ans = [d1 + d2 + d3,
			2 * d1 + 2 * d2,
			2 * d1 + 2 * d3,
			2 * d2 + 2 * d3].min
		puts ans
	end
end

Solver.new.main
class Solver
	def main
		l = gets.to_i
		p = gets.to_i
		q = gets.to_i

		t = 1.0 * l / (p + q)
		dis = t * p

		puts dis
	end
end

Solver.new.main
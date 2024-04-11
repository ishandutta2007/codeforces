class Solver
	def main
		n = gets.to_i
		if n.odd? || n < 4
			puts 0
		else
			n = n / 2
			puts (n - 1) / 2
		end
	end
end
Solver.new.main
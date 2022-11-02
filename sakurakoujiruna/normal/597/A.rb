class Solver
	def main
		k, a, b = gets.split.map { |x| x.to_i }
		if 0.between? a, b then
			puts b / k + (-a) / k + 1
		else
			a, b = -b, -a if b < 0
			puts b / k - (a - 1) / k
		end
	end
end

Solver.new.main
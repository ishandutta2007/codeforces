class Solver
	def main
		d, l, v1, v2 = gets.split.map { |x| x.to_i }
		puts format("%.8f", (l - d).to_f / (v1 + v2).to_f)
	end
end
Solver.new.main
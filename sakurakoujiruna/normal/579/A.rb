class Solver
	def main
		n = gets.to_i
		ans = (0..30).to_a.count { |i| n[i] == 1 }
		puts ans
	end
end

Solver.new.main
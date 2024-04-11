class Solver
	def main
		n, s = gets.split.map { |x| x.to_i }
		ans = []
		n.times do
			f, t = gets.split.map { |x| x.to_i }
			ans << [t, s - f].max + f
		end
		puts ans.max
	end
end
Solver.new.main
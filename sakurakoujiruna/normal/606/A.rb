class Solver
	def main
		have = gets.split.map { |x| x.to_i }
		need = gets.split.map { |x| x.to_i }
		0.upto(2) do |i|
			tmp = [have[i], need[i]].min
			have[i] -= tmp
			need[i] -= tmp
			have[i] /= 2
		end
		str = ["Yes", "Yes", "No"]
		puts str[have.reduce(:+) <=> need.reduce(:+)]
	end
end

Solver.new.main
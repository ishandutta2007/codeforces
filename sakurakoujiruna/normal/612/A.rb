class Solver
	def main
		n, a, b = gets.split.map { |x| x.to_i }
		str = gets.chomp
		0.upto(n) do |l|
			r = n - l
			if l % a == 0 && r % b == 0
				puts l / a + r / b
				0.upto(l / a - 1) do |i|
					puts str[i * a, a]
				end
				0.upto(r / b - 1) do |i|
					puts str[l + i * b, b]
				end
				return
			end
		end
		puts -1
	end
end
Solver.new.main
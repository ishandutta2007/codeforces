class Solver
	def main
		a, b = gets.split.map { |x| x.to_i }
		ans = 0
		2.upto(64) do |n|
			0.upto(n - 2) do |i|
				x = ((1 << n) - 1) ^ (1 << i)
				ans += 1 if x.between? a, b
			end
		end
		puts ans
	end
end
Solver.new.main
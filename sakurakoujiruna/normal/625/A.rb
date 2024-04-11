class Solver
	def main
		n = gets.to_i
		a = gets.to_i
		b = gets.to_i
		c = gets.to_i
		if b - c >= a
			puts n / a
		else
			ans = 0
			if n >= c
				ans += (n - c) / (b - c)
				n -= (n - c) / (b - c) * (b - c)
			end
			ans += n / [a, b].min
			puts ans
		end
	end
end
Solver.new.main
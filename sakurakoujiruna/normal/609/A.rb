class Solver
	def main
		n = gets.to_i
		m = gets.to_i
		a = []
		n.times do
			a << gets.to_i
		end
		a = a.sort.reverse
		ans = 0
		a.each do |x|
			if m > 0
				m -= x
				ans += 1
			end
		end
		puts ans
	end
end
Solver.new.main
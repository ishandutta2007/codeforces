class Solver
	def main
		f = gets.split
		x = f[0].to_i
		type = f[-1]
		if type == "week"
			if x.between? 5, 6
				puts 53
			else
				puts 52
			end
		else
			ans = 12
			ans -= 1 if x > 29
			ans -= 4 if x > 30
			puts ans
		end
	end
end
Solver.new.main
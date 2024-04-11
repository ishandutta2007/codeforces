require 'prime'

class Solver
	def main
		n = gets.to_i
		ans = []
		2.upto(n) do |i|
			if Prime.prime? i
				tmp = i
				while tmp <= n do
					ans << tmp
					tmp *= i
				end
			end
		end
		puts ans.size
		puts ans.join ' '
	end
end
Solver.new.main
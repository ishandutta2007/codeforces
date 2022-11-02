class Solver
	def main
		n = gets.to_i
		ans = n * (n + 1) / 2
		tmp = 1
		while tmp <= n do
			ans -= 2 * tmp
			tmp *= 2
		end
		puts ans
	end
end

case_cnt = gets.to_i
case_cnt.times do
	Solver.new.main
end
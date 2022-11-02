class Solver
	def main
		n = gets.to_i

		ans = 1
		2.upto(n) do |i|
			break if i * i > n
			if n % i == 0 then
				ans *= i
				n /= i while n % i == 0
			end
		end
		ans *= n

		puts ans
	end
end

Solver.new.main
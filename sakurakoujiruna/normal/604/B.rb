class Solver
	def main
		n, k = gets.split.map { |x| x.to_i }
		s = gets.split.map { |x| x.to_i }
		k = n if k > n

		ans = 0
		while 2 * k != n do
			ans = [ans, s.pop].max
			k -= 1
			n -= 1
		end

		s = s.zip(s.reverse)
		ans = (s.map { |x| x[0] + x[1] } << ans).max
		puts ans
	end
end

Solver.new.main
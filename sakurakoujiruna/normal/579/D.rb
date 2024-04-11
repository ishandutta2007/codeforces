class Solver
	def main
		n, k, x = gets.split.map { |s| s.to_i }
		a = gets.split.map { |s| s.to_i }
		a.unshift nil
		x = x ** k

		prefix_or = Array.new(n + 2)
		suffix_or = Array.new(n + 2)
		prefix_or[0] = suffix_or[n + 1] = 0
		1.upto(n) do |i|
			prefix_or[i] = (prefix_or[i - 1] | a[i])
		end
		n.downto(1) do |i|
			suffix_or[i] = (suffix_or[i + 1] | a[i])
		end

		ans = 0
		1.upto(n) do |i|
			ans = [ans, (a[i] * x) | prefix_or[i - 1] | suffix_or[i + 1]].max
		end
		puts ans
	end
end

Solver.new.main
class Solver
	def main
		n = gets.to_i
		f = gets.split.map { |x| x.to_i }
		pos = Array.new(n + 1, 0)
		f.each.with_index do |x, i|
			pos[x] = i
		end
		ans = 0
		1.upto(n - 1) do |i|
			ans += (pos[i] - pos[i + 1]).abs
		end
		puts ans
	end
end
Solver.new.main
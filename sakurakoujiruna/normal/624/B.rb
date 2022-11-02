class Solver
	def main
		n = gets.to_i
		arr = gets.split.map { |x| x.to_i }
		arr = arr.sort.reverse

		ans = 0
		last = 1 << 30
		arr.each do |x|
			x = last - 1 if x >= last
			ans += x if x >= 0
			last = x
		end
		puts ans
	end
end
Solver.new.main
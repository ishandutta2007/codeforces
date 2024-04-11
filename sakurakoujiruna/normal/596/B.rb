class Solver
	def main
		n = gets.to_i
		b = gets.split.map { |x| x.to_i }
		last = 0
		ans = 0
		b.each do |x|
			x -= last
			ans += x.abs
			last += x
		end
		puts ans
	end
end

Solver.new.main
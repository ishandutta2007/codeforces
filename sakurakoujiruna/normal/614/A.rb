class Solver
	def main
		l, r, k = gets.split.map { |x| x.to_i }
		ans = []
		64.times do |i|
			x = k ** i
			ans << x if x.between? l, r
		end
		if ans.empty?
			puts -1
		else
			puts ans.join ' '
		end
	end
end

Solver.new.main
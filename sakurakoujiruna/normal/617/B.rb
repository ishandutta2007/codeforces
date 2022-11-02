class Solver
	def main
		n = gets.to_i
		arr = gets.split.map { |x| x.to_i }

		ans = 1
		last = nil
		arr.each.with_index do |v, id|
			if v == 1
				ans *= (id - last) if last != nil
				last = id
			end
		end
		ans = 0 if arr.count(1) == 0
		puts ans
	end
end
Solver.new.main
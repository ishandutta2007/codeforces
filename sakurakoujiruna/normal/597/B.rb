class Solver
	def main
		n = gets.to_i
		orders = []
		n.times do
			orders << gets.split.map{ |x| x.to_i }
		end
		orders.sort! { |a, b| a[1] <=> b[1] }

		ans = 0
		last = 0
		orders.each do |order|
			if order[0] > last then
				last = order[1]
				ans += 1
			end
		end
		puts ans
	end
end

Solver.new.main
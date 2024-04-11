class Solver
	def main
		n = gets.to_i
		p = []
		n.times do
			p << Hash[[:x, :y].zip(gets.split.map{ |x| x.to_i })]
		end
		if n == 1 then
			puts -1
		elsif n == 2 then
			if p[0][:x] == p[1][:x] || p[0][:y] == p[1][:y] then
				puts -1
			else
				puts (p[0][:x] - p[1][:x]).abs *
					(p[0][:y] - p[1][:y]).abs
			end
		else
			x = p.map{ |poi| poi[:x] }.uniq
			y = p.map{ |poi| poi[:y] }.uniq
			puts (x[1] - x[0]).abs * (y[1] - y[0]).abs
		end
	end
end

Solver.new.main
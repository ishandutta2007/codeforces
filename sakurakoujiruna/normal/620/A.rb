class Solver
	def main
		x1, y1 = gets.split.map { |x| x.to_i }
		x2, y2 = gets.split.map { |x| x.to_i }
		dx = (x1 - x2).abs
		dy = (y1 - y2).abs
		puts [dx, dy].max
	end
end

Solver.new.main
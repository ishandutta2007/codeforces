class Solver
	def main
		n, m = gets.split.map { |x| x.to_i }
		f = Array.new(m + 1, false)
		n.times do
			a = gets.split.map { |x| x.to_i }
			a.shift
			a.each do |x|
				f[x] = true
			end
		end
		cnt = f.count(true)
		if cnt == m
			puts "YES"
		else
			puts "NO"
		end
	end
end
Solver.new.main
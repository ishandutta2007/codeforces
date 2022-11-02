class Solver
	def main
		n = gets.to_i
		h = gets.split.map { |x| x.to_i }
		pre_max = Array.new(n + 2, 0)
		suf_min = Array.new(n + 2, 1e9.to_i)
		1.upto(n) do |i|
			pre_max[i] = [pre_max[i - 1], h[i - 1]].max
		end
		n.downto(1) do |i|
			suf_min[i] = [suf_min[i + 1], h[i - 1]].min
		end
		gap = (1...n).count { |i| pre_max[i] <= suf_min[i + 1] }
		puts gap + 1
	end
end

Solver.new.main
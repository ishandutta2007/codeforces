class Solver
	def read_number
		n, base = gets.split.map { |x| x.to_i }
		f = gets.split.map { |x| x.to_i }
		f.reverse.map.with_index { |v, id| v * (base ** id) }.reduce(:+)
	end
	def main
		a = read_number
		b = read_number
		output = ["=", ">", "<"]
		puts output[a <=> b]
	end
end

Solver.new.main
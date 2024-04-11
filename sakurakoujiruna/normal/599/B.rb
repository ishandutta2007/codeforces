class Solver
	def main
		n, m = gets.split.map { |x| x.to_i }
		f = gets.split.map { |x| x.to_i }
		b = gets.split.map { |x| x.to_i }
		h = Hash.new { |hash, key| hash[key] = Array.new }
		f.each.with_index do |x, id|
			h[x] << id
		end

		ambiguity = false
		impossible = false
		ans = []
		b.each do |x|
			if h[x].size == 0 then
				impossible = true
			elsif h[x].size > 1 then
				ambiguity = true
			else
				ans << h[x][0] + 1
			end
		end
		if impossible then
			puts "Impossible"
		elsif ambiguity then
			puts "Ambiguity"
		else
			puts "Possible"
			puts ans.join " "
		end
	end
end

Solver.new.main
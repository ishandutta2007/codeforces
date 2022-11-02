class Solver
	def gcd(a, b)
		return a if b == 0
		gcd(b, a % b)
	end
	def lcm(a, b)
		a * b / gcd(a, b)
	end

	def main
		t, w, b = gets.split.map { |s| s.to_i }
		t += 1

		part = lcm(w, b)
		start = [w, b].min

		cnt = -1
		cnt += t / part * start
		cnt += [t % part, start].min

		g = gcd(cnt, t - 1)
		print cnt / g, ?/, (t - 1) / g, ?\n
	end
end

Solver.new.main
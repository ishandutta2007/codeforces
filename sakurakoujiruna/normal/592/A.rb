class Solver
	def main
		f = []
		8.times { f << gets }
		ans_w = 10
		ans_b = 10
		8.times do |i|
			8.times do |j|
				if f[i][j] == "W" then
					flag = true
					tmp = i - 1
					while tmp >= 0 do
						flag = false if f[tmp][j] != '.'
						tmp -= 1
					end
					ans_w = [ans_w, i].min if flag
				elsif f[i][j] == "B" then
					flag = true;
					tmp = i + 1
					while tmp < 8 do
						flag = false if f[tmp][j] != '.'
						tmp += 1
					end
					ans_b = [ans_b, 7 - i].min if flag
				end
			end
		end
		puts ans_w <= ans_b ? "A" : "B"
	end
end

Solver.new.main
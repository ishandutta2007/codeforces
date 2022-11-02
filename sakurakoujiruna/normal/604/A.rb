class Solver
	def main
		max_score = [500, 1000, 1500, 2000, 2500]
		last_submission_time = gets.split.map { |x| x.to_i }
		wrong_submissions = gets.split.map { |x| x.to_i }
		successful_hacks, unsuccessful_hacks = gets.split.map { |x| x.to_i }

		problem_score = Array.new(5, 0)
		0.upto(5 - 1) do |i|
			lhs = max_score[i] * 3 / 10
			rhs = max_score[i] - max_score[i] / 250 * last_submission_time[i] \
				- wrong_submissions[i] * 50
			problem_score[i] = [lhs, rhs].max
		end

		total_score = problem_score.reduce(:+)
		total_score += successful_hacks * 100
		total_score -= unsuccessful_hacks * 50
		puts total_score
	end
end

Solver.new.main
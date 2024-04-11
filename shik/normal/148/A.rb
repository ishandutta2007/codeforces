*a, n = $<.read.split.map(&:to_i)
p (1..n).count{|x| a.any?{|y| x % y == 0}}
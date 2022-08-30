def find_earliest(s, forbid)
	(0...100000).each{ |i|
		s2 = (i == 0 ? "" : i.to_s) + s
		if s2.to_i >= 1989 && !forbid.include?(s2.to_i)
			return s2.to_i
		end
	}
end

n = gets.chomp.to_i

n.times {
	s = gets.chomp[4..-1]
	forbid = []
	ans = 0
	(1..s.size).each{ |i|
		ans = find_earliest(s[(-i)..-1], forbid)
		forbid.push ans
	}
	puts ans
}
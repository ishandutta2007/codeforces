n = gets.to_i
puts n.times.map{gets}.count{|x| x.count('1') >= 2}
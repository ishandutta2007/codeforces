n, h = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
ans = a.map{|x| x <= h ? 1 : 2}.inject(:+)
puts ans
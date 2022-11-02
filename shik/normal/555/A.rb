n, k = gets.split.map(&:to_i)
a = k.times.map{gets.split.map(&:to_i).drop(1)}.find{|x| x[0] == 1}
puts n + n - k + 1 - 2 * a.map.with_index(1).take_while{|x, i| x == i}.size
len = 0
a, b = (0...2).map {len = gets.chomp
len.to_i 2}
c = (a ^ b).to_s 2
puts '0' * (len.length - c.length) + c
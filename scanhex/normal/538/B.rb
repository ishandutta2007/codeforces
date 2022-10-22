n = gets.chomp.scan(/./)
maxx = n.map {|i| i.to_i}.max
puts maxx
for i in 0...maxx
  x = [0] * n.length
  for j in 0...n.length
    if n[j].to_i != 0
      x[j] = 1
      n[j] = (n[j].to_i - 1).to_s
    end
  end
  print x.join('').to_i, ' '
end
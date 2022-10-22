x, y = gets.split.map { |x| Integer x }
p1 = 1.0
p2 = 1000.0
for i in 1..2000
  if p1 ** 2 + p2 ** 2 > x ** 2
    p2 -= 1
  elsif p1 ** 2 + p2 ** 2 < x ** 2
    p1 += 1
  else
    arc = Math.acos(p1 / x)
    arc2 = Math::PI / 2 - arc
    p3 = y * Math.cos(arc2)
    p4 = Math.sqrt (y ** 2 - p3.round ** 2)
    if (p3.round - p3).abs <= 10 ** -9 && (p4 - p4.round).abs <= 10 ** -9
      if [p1, p3, p2, p4].index(0) != nil
        puts 'NO'
        exit
      end
      if p2.round == p4.round
        puts 'YES'
        puts (-p2.to_i).to_s + ' ' + p1.to_i.to_s
        puts '0 0'
        puts p4.round.to_s + ' ' + p3.round.to_s
        exit
      end
      puts 'YES'
      puts (-p1.to_i).to_s + ' ' + (p2.to_i).to_s
      puts '0 0'
      puts p3.round.to_s + ' ' + p4.round.to_s
      exit
    end
    p1 += 1
    p2 -= 1
  end
end
puts 'NO'
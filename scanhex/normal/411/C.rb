a1, b1 = gets.split.map {|x| Integer x}
a2, b2 = gets.split.map {|x| Integer x}
a3, b3 = gets.split.map {|x| Integer x}
a4, b4 = gets.split.map {|x| Integer x}
if (a1 > b3 && a1 > b4 && b2 > a3 && b2 > a4) || (b1 > a3 && b1 > a4 && a2 > b3 && a2 > b4)
  puts 'Team 1'
elsif (a3 > b1 && b4 > a2 || b3 > a2 && a4 > b1) && (b3 > a1 && a4 > b2 || b4 > a1 && a3 > b2)
  puts 'Team 2'
else
  puts 'Draw'
end
n = gets.to_i
x = 0
n.times do
  s = gets.chomp
  case s
  when '++X', 'X++'
    x += 1
  when '--X', 'X--'
    x -= 1
  end
end
puts x
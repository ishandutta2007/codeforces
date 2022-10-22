n, a = gets.split.map &:to_i
if a % 2 == 0
  a = n - a + 1
end
puts a / 2 + 1
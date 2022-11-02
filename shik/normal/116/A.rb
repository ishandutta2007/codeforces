n = gets.to_i
now = 0
ans = 0
n.times do
  a, b = gets.split.map(&:to_i)
  now += b - a
  ans = [ans, now].max
end
puts ans
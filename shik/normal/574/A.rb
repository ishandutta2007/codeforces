n = gets.to_i
a = gets.split.map(&:to_i)
ans = 0
while a.drop(1).any?{|x| x >= a[0]}
  ans += 1
  i = a.drop(1).map.with_index(1).max[1]
  a[0] += 1
  a[i] -= 1
end
puts ans
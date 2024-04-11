n = gets.to_i
m = 1
while 5 * m < n
  n -= 5 * m
  m *= 2
end
puts ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"][(n - 1) / m]
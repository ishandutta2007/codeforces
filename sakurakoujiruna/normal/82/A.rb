Names = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]

n = gets.to_i
n -= 1

n = (n - 5) / 2 while n >= 5
puts Names[n]
n, m = gets.split.map {|i| i.to_i }
if n < m
  puts -1
  exit
end
puts (n + 1) / 2 + (m - ((n + 1) / 2) % m) % m
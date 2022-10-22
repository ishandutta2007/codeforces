p, n = gets.split.map {|i| i.to_i}
a = Array.new(p)
for i in 0...n
  x = gets.to_i
  if a[x % p] != nil
    puts i + 1
    exit
  end
  a[x % p] = true
end
puts -1
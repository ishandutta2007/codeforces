m, n = gets.split.map {|i| i.to_i}
a = []
for i in 0...m
  a.push(((i + 1).to_f / m) ** n)
end
(1...m).reverse_each {|i|
  a[i] -= a[i - 1]
}
sum = 0
for i in 0...m
  sum += (i + 1) * a[i]
end
puts sum
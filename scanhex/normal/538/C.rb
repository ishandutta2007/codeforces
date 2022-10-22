n, m = gets.split.map {|i| i.to_i}
b1, a1 = gets.split.map {|i| i.to_i}
maxx = a1 + b1 - 1
for i in 0...m - 1
  b, a = gets.split.map {|i| i.to_i}
  maxx = [maxx, (b - b1 + a1 + a) / 2].max
  if (a1 - a).abs > (b1 - b).abs
    print 'IMPOSSIBLE'
    exit(0)
  end
  a1, b1 = a, b
end
print [maxx, a1 + n - b1].max
# a - a1 + a - a2 <= b2 - b1
# a + a <= b2 - b1 + a1 + a2
# a <= (b2 - b1)
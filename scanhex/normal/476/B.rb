s1 = gets.chomp.scan(/./)
s2 = gets.chomp.scan(/./)
n = s1.length
d = Array.new(n + 1)
for i in 0..n
  d[i] = Array.new(21, 0)
end
d[0][10] = 1.0
for i in 0...n
  for j in 0...21
    if s2[i] == '+'
      d[i + 1][j] = j > 0 ? d[i][j - 1] : 0
    end
    if s2[i] == '-'
      d[i + 1][j] = j < 20 ? d[i][j + 1] : 0
    end
    if s2[i] == '?'
      d[i + 1][j] = ((j > 0 ? d[i][j - 1] : 0) + (j < 20 ? d[i][j + 1] : 0)) / 2
    end
  end
end
sum = 0
for x in s1
  sum += (x == '+' ? 1 : -1)
end
puts d[n][sum + 10]
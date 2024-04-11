def check(m, c1, c2, x, y)
  c1 -= m / y - m / (x * y)
  c2 -= m / x - m / (x * y)
  c1 = [c1, 0].max
  c2 = [c2, 0].max
  m - m / x - m / y + m / (x * y) >= c1 + c2
end
cnt1, cnt2, x, y = gets.split.map {|i| i.to_i}
l, r = 1, 10 ** 10
while r - l > 1
  m = (r + l) / 2
  if check(m, cnt1, cnt2, x, y)
    r = m
  else
    l = m
  end
end
puts r
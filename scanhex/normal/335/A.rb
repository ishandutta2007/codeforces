s = gets.chomp.scan(/./)
n = gets.to_i
a = [0] * 26
for x in s
  a[x.ord - 'a'.ord] += 1
end
l, r = 0, s.length
while r - l > 1
  m = (r + l) / 2
  cnt = n
  for i in 0...26
    if a[i] != 0
      cnt -= (m + a[i] - 1) / m
    end
  end
  if cnt >= 0
    r = m
  else
    l = m
  end
end
ans = ''
for i in 0...26
  if a[i] != 0
    ans += (i + 'a'.ord).chr * ((a[i] + r - 1) / r)
  end
end
if n >= ans.length
  ans += 'a' * (n - ans.length)
else
  puts -1
  exit
end
puts r
puts ans
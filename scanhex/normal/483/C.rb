n, k = gets.split.map { |i| i.to_i }
ans = []
if k == n - 1
  for i in 0...n
    print i % 2 == 0 ? i / 2 + 1 : n - i / 2
    print ' '
  end
  exit(0)
end
for i in 0...k / 2
  ans.push i, n - i - 1
end
for i in k / 2...n - k / 2
  ans.push i
end
if k % 2 == 0
  ans[0], ans[1] = ans[1], ans[0]
end
for x in ans
  print (x + 1).to_s + ' '
end
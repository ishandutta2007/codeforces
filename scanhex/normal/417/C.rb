n, k = gets.split.map {|x| Integer x}
if k * n > n * (n - 1) / 2
  puts -1
  exit
end
am = Array.new(n)
cnt = Array.new(n, n - 1)
for i in 0...n
  am[i] = Array.new(n)
end
for i in 0...n
  c = 0
  for j in 0...n
    if cnt[j] == k || i == j || am[i][j] != nil
      next
    end
    am[i][j] = true
    am[j][i] = false
    c += 1
    if c == k
      break
    end
  end
end
ans = []
for i in 0...n
  for j in 0...n
    if am[i][j]
      ans.push((i + 1).to_s + ' ' + (j + 1).to_s)
    end
  end
end
puts ans.length
puts ans
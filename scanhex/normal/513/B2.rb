n, m = gets.split.map {|i| i.to_i}
m -= 1
arr = [nil] * n
k = 1 << (n - 2)
p1 = 0
p2 = -1
for i in 1..n
  if m >= k
    m -= k
    arr[p2] = i
    p2 -= 1
  else
    arr[p1] = i
    p1 += 1
  end
  k >>= 1
end
puts arr.join ' '
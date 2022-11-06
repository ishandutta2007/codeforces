n = gets.to_i
h = [0] * 100001
a = Array.new(n + 1)
for i in 1..n
  y = gets.split(" ").collect {|x| x.to_i}
  h[y[0]] += 1
  a[i] = y[1]
end
for i in 1..n
  printf("%d %d\n", n - 1 + h[a[i]], n - 1 - h[a[i]])
end
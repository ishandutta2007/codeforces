n = Integer gets
k = gets.split.map {|x| Integer x}
ans = Array.new(n, 0)
for i in 0..n - 1
  sum = 0
  arr = gets.split.map {|x|
    sum += Integer x
    Integer x
  }
  ans[i] += sum * 5 + 15 * arr.length
end
puts ans.min
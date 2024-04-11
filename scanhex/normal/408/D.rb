def f(x)
  if @d[x] != nil
    return @d[x]
  end
  sum = 1
  for i in @p[x]..x - 1
    sum += f(i)
  end
  sum += 1
  @d[x] = sum
  sum
end

n = Integer gets
@p = gets.split.map { |x| (Integer x) - 1 }
@d = Array.new(n, nil)
@d[0] = 2
sum = 0
for i in 0..n - 1
  sum += f i
end
puts sum % (10 ** 9 + 7)
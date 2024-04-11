n = gets.to_i
p = n.times.map{gets.split.map(&:to_i)}.sort
ans = n * (n - 1) * (n - 2) / 6
n.times do |i|
  c = 1
  (i + 1)
    .upto(n - 1)
    .map{|j| (p[j][1] - p[i][1]).to_f / (p[j][0] - p[i][0])}
    .sort
    .each_cons(2) do |a, b|
      if a == b
        c += 1
      else
        ans -= c * (c - 1) / 2;
        c = 1
      end
    end
  ans -= c * (c - 1) / 2
end
puts ans
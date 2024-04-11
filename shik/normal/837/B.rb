def build(n, m)
  'RGB'.chars.permutation.map do |cs|
    cs.flat_map{|c| n.times.map{(c * m).chars}}
  end
end

n, m = gets.split.map(&:to_i)
s = n.times.map{gets.strip.chars}
ts = build(n / 3, m) + build(m / 3, n).map(&:transpose)

if ts.include?(s)
  puts 'YES'
else
  puts 'NO'
end
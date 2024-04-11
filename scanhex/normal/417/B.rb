require 'set'
n = Integer gets
a = Array.new(10 ** 5)
cnt = Array.new(10 ** 5, 0)
for i in 0...10**5
  a[i] = [].to_set
end
for i in 0...n
  x, k = gets.split.map {|x| Integer x}
  k -= 1
  if !a[k].include?(x) && x != cnt[k]
    puts 'NO'
    exit
  end
  unless a[k].include?(x)
    a[k].add(cnt[k])
    cnt[k] += 1
  end
end
puts 'YES'
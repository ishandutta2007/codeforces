n = gets.to_i
p = gets.split.map(&:to_i).map{|x| x - 1}

if p.uniq.size != n
  puts(-1)
  exit
end

ls = []
n.times do |i|
  x = p[i]
  len = 1
  until x == i
    x = p[x]
    len += 1
  end
  ls << len
end

ans = 1
ls.each do |l|
  l /= 2 if l.even?
  ans = ans.lcm(l)
end
puts ans
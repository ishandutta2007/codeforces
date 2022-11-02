def solve(a, b, k)
  return -1 if a.size + b.size < k
  return -1 if a.empty? || b.empty?
  a = a.dup
  b = b.dup
  s = a.pop + b.pop
  (k - 2).times do
    if a.any? && (b.empty? || a.last > b.last)
      s += a.pop
    else
      s += b.pop
    end
  end
  s
end

n, k = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)
c = gets.strip

if k == 1
  puts -1
  exit
end

fw = []
fo = []
fr = []
n.times do |i|
  case c[i]
  when 'W'
    fw << b[i]
  when 'O'
    fo << b[i]
  when 'R'
    fr << b[i]
  else
    fail
  end
end

fw.sort!
fo.sort!
fr.sort!

sw = solve(fw, fo, k)
sr = solve(fr, fo, k)
ans = [sw, sr].max
puts ans
# Created by Alex
n, m = gets.split.map{|i| i.to_i}
if n == 1 && m == 1
  puts '1 1', '0 0', '1 0', '0 1'
  exit 0
end
if n == 0
  puts '0 1', "0 #{m}", '0 0', "0 #{m - 1}"
  exit 0
end
if m == 0
  puts '1 0', "#{n} 0", '0 0', "#{n - 1} 0"
  exit 0
end
a1 = Math.hypot(n, m) + 2 * [Math.hypot(n - 1, m), Math.hypot(n, m - 1)].max
a2 = Math.hypot(n, m) * 2 + [n, m].max
if a2 > a1
  if n > m
    puts '0 0', "#{n} #{m}", "0 #{m}", "#{n} 0"
  else
    puts '0 0', "#{n} #{m}", "#{n} 0", "0 #{m}"
  end
else
  if Math.hypot(n - 1, m) > Math.hypot(n, m - 1)
    puts '1 0', "#{n} #{m}", '0 0', "#{n - 1} #{m}"
  else
    puts '0 1', "#{n} #{m}", '0 0', "#{n} #{m - 1}"
  end
end
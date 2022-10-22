l, r = gets.split.map {|i| i.to_i}
if r - l == 2 && l % 2 == 1 || r - l < 2
  puts -1
else
  if l % 2 == 1
    l += 1
  end
  puts l.to_s + ' ' + (l + 1).to_s + ' ' + (l + 2).to_s
end
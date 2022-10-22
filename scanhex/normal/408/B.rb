a = gets.chomp
b = gets.chomp
cnt1 = Hash.new
cnt2 = Hash.new
for x in a.scan /./
  if cnt1[x] == nil
    cnt1[x] = 0
  end
  cnt1[x] += 1
end
for x in b.scan /./
  if cnt2[x] == nil
    cnt2[x] = 0
  end
  cnt2[x] += 1
end
ans = 0
cnt2.each_pair do |k, v|
  if cnt1[k] == nil
    puts -1
    exit
  end
  ans += [v, cnt1[k]].min
end
puts ans
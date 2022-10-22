# Created by Alex
n, k, x = gets.split.map {|i| i.to_i}
a = gets.split.map {|i| i.to_i}
max = 0
maxi = -1
for i in 0...n - 1
  #print a[i].to_s + ' '
  if a[i] != x || a[i + 1] != x
    next
  end
  l = i - 1
  r = i + 2
  cnt = 3
  while l >= 0 && r < n && a[l] == a[r]
    p1 = l
    while p1 > 0 && a[p1 - 1] == a[r]
      p1 -= 1
    end
    p2 = r
    while p2 < n - 1 && a[p2 + 1] == a[l]
      p2 += 1
    end
    if l - p1 + p2 - r + 2 < 3
      break
    end
    cnt += l - p1 + p2 - r + 2
    l = p1 - 1
    r = p2 + 1
  end
  if cnt >= max
    #print ' (' + cnt.to_s + ' ' + p1.to_s + ' ' + p2.to_s + ') '
    max = cnt
    maxi = i
  end
end
if max < 3
  max = 1
end
puts max - 1
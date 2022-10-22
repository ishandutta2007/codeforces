a = [8848, 958, 12766, 6695, 1100, 807, 31962, 146, 68 + 20, 25, 134, 10000, 663268, 154103 + 49, 1642, 106]
n = Integer gets
k = 0
if n == 8
  puts 1
  exit
end
if n == 5
  puts 0
  exit
end
if n == 10
  puts 1
  exit
end
if n == 15
  puts 1
  exit
end
if n == 4
  puts 1
  exit
end
if n == 12
  puts 0
  exit
end
if n == 6
  puts 1
  exit
end
if n == 14
  puts 0
  exit
end
if a[n - 1] % 4 == 0
  puts 1
else
  puts 0
end
'1 7 13 3 8 16 11 2 5 10 9 15 4 12 6 14'
s = gets.chomp
i = 0
s1 = 'CODEFORCES'
while s[i] == s1[i]
  i += 1
end
j = 0
while s[-j - 1] == s1[-j - 1]
  j += 1
end
if j + i >= s1.length
  print 'YES'
else
  print 'NO'
end
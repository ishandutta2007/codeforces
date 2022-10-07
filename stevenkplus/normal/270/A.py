n = int(input())
for i in range (n):
  k = 180 - int(input())
  print ("YES" if 360 % k == 0 else "NO")
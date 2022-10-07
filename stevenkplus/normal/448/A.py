a, b, c = [int(x) for x in raw_input().split()]
m = (a + b + c + 4) / 5
a, b, c = [int(x) for x in raw_input().split()]
m += (a + b + c + 9) / 10
n = input()
if m <= n:
  print "YES"
else:
  print "NO"
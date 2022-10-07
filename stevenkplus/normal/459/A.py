a,b,c,d = map(int, raw_input().split())
s = abs(c - a)
t = abs(d - b)
if s > 0 and t > 0 and s != t:
  print -1
else:
  if s == 0:
    a = c = a + t
  elif t == 0:
    b = d = b + s
  else:
    b, d = d, b
  print a, b, c, d
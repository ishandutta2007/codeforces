n = input()
s = raw_input()
t = raw_input()

a = b = c = 0
for i in xrange(2*n):
  if (s[i] == '1' and t[i] == '1'):
    a = a + 1
  elif (s[i] == '1' and t[i] == '0'):
    b = b + 1
  elif (s[i] == '0' and t[i] == '1'):
    c = c + 1
ans = 0
for i in range(2*n):
    if a > 0:
        ans = ans + 1
        a = a - 1
    elif b > 0:
        ans = ans + 1
        b = b - 1
    elif c > 0:
        c = c - 1
        
    if a > 0:
        ans = ans - 1
        a = a - 1
    elif c > 0:
        ans = ans - 1
        c = c - 1
    elif b > 0:
        b = b - 1
        
if ans == 0:
    print "Draw"
if ans > 0:
    print "First"
if ans < 0:
    print "Second"
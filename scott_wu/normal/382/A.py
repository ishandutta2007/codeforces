s = raw_input()
t = raw_input()

a, b = s.find ('|'), len(s) - s.find ('|') - 1

#print a
#print b

if (a + b + len(t)) % 2 == 0 and abs (a - b) <= len (t):
    print t[:(b+len(t)-a)/2] + s + t[(b+len(t)-a)/2:]
else:
    print """Impossible"""
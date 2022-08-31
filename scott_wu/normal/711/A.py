n = input()
r = [raw_input() for i in xrange(n)]

found = False
for i in xrange(n):
    if 'OO' in r[i]:
        m = r[i].index('OO')
        r[i] = r[i][:m] + '++' + r[i][m+2:]
        found = True
        break

if found:
    print "YES"
    print "\n".join(i for i in r)
else:
    print "NO"
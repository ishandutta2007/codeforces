n = input()
d = {}

for i in xrange(n):
    a = raw_input()
    if a not in d:
        print "OK"
        d[a] = 1
    else:
        print a + str(d[a])
        d[a] += 1
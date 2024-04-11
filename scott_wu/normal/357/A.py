m = int(raw_input())

c = map (int, raw_input().split())
x, y = (int(s) for s in raw_input().split())

#print c

for i in xrange(m):
    if sum (c[:i]) >= x and sum (c[:i]) <= y and sum (c[i:]) >= x and sum (c[i:]) <= y:
        print i + 1
        break
else:
    print 0
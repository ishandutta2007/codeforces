n, a = input(), 0
for i in xrange(n):
    x, y = map(int, raw_input().split())
    if x >= y:
        a += 1
    if x > y:
        a += 1

if a > n:
    print "Mishka"
elif a == n:
    print "Friendship is magic!^^"
else:
    print "Chris"
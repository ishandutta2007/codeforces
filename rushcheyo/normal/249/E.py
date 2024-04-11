def solve(x, y):
    if x > y:
	    return (4 * x + 3 * x * x + 2 * x * x * x - y - 3 * x * y + y * y * y) * y / 6
    else:
        return (-x + x * x * x + 4 * y + 3 * x * y - 3 * y * y + 2 * y * y * y) * x / 6

T = input()
for i in xrange(T):
    a, b, c, d=map(int, raw_input().split())
    ret = solve(c, d) - solve(a - 1, d) - solve(c, b - 1) + solve(a - 1, b - 1)
    if ret < 10 ** 10:
        print ret
    else:
        print "...%010d" %(ret % (10 ** 10))
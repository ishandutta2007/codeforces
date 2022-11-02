n, t, k, d = map(int, raw_input().split())
t1 = (n + k - 1) / k * t
t2 = int(1e30)
for j in xrange(n + 1):
    t2 = min(t2, max((j + k - 1) / k * t, d + (n - j + k - 1) / k * t))

print "YES" if t2 < t1 else "NO"
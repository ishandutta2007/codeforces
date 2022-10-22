n = input()
a = map(int , raw_input().split(' '))
for i in xrange(n):
    p = 1 << 32
    if i > 0:
        p = min(p , a[i] - a[i - 1])
    if i + 1 < n:
        p = min(p , a[i + 1] - a[i])
    q = -1 << 32
    if i != 0:
        q = max(q , a[i] - a[0])
    if i != n - 1:
        q = max(q , a[n - 1] - a[i])
    print p , q
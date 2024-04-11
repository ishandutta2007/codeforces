__author__ = 'Alex'
n, t1, t2, k = [int(i) for i in input().split()]
u, v = [], []
for i in range(n):
    a, b = [int(i) for i in input().split()]
    u.append(a)
    v.append(b)
a = []
for j in range(n):
        a.append((-max(t1 * u[j] * (100 - k) / 100 + t2 * v[j], t1 * v[j] * (100 - k) / 100 + t2 * u[j]), j))
a.sort()
for i in range(n):
    print("%d %2.2f" % (a[i][1] + 1, -a[i][0]))
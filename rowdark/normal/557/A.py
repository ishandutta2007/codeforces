n = int(raw_input())
a, b = map(int, raw_input().split())
n -= a
b -= a
c, d = map(int, raw_input().split())
n -= c
d -= c
e, f = map(int, raw_input().split())
n -= e
f -= e
b = min(n, b)
n -= b
d = min(d, n)
n -= d
f = min(f, n)
n -= f
print a + b, c + d, e + f
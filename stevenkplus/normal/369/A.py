n,m,k = [int(_) for _ in raw_input().split()]
ar = [int(_) for _ in raw_input().split()]

a = sum(1 for _ in ar if _ == 1) # bowl required

ans = 0
tot = m + k
if a <= m:
  tot -= a
else:
  tot -= m
  ans += a - m

b = n - a
if b > tot:
  ans += b - tot

print ans
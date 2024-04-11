import sys
from collections import defaultdict

n, m = map(int, sys.stdin.readline().rstrip('\n').split(' '))

p = defaultdict(list)
for _ in range(n):
	x, y = map(int, sys.stdin.readline().rstrip('\n').split(' '))
	p[x].append(y)

for key in p:
	p[key] = sorted(p[key])

ans = 10**100
for k in range(1, n + 1):
	cur = 0
	r = []
	for key in p:
		if key == 1:
			continue
		a = p[key]
		cnt = max(0, len(a) - (k - 1))
		cur += sum(a[:cnt])
		r += a[cnt:]
	r = sorted(r)
	cnt = max(0, len(r) - (n - k))
	cur += sum(r[:cnt])
	ans = min(ans, cur)
	
print(ans)
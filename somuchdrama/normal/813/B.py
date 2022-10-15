x, y, l, r = map(int, input().split())
xs = [x ** i for i in range(61) if x ** i <= 10 ** 18]
ys = [y ** i for i in range(61) if y ** i <= 10 ** 18]
ps = set()
for i in xs:
	for j in ys:
		if l <= i + j <= r:
			ps.add(i + j)
ps.add(l - 1)
ps.add(r + 1)
ps = sorted(list(ps))
ans = 0
for i in range(1, len(ps)):
	ans = max(ans, ps[i] - ps[i - 1] - 1)
print(ans)
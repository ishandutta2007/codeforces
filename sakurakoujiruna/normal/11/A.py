n, d = [int(x) for x in raw_input().split()]
a = [int(x) for x in raw_input().split()]

ans = 0
for i in range(1, n) :
	if a[i - 1] >= a[i] :
		add = (a[i - 1] - a[i] + 1 + d - 1) / d
		a[i] += add * d
		ans += add

print ans
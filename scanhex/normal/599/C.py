n = int(input())
a = [int(i) for i in input().split()]
pref = [0] * (n + 1)
for i in range(n):
	pref[i + 1] = max(pref[i], a[i])
suff = [0] * n
suff[n - 1] = a[n - 1]
for i in range(n - 2, -1, -1):
	suff[i] = min(suff[i + 1], a[i])
c = 0
for i in range(n):
	if pref[i] <= suff[i]:
		c += 1
print(c)
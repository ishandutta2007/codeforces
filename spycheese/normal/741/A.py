n = int(input())
w = map(int, input().split())
w = [x-1 for x in w]

ws = sorted(w)
for i in range(n):
	if i != ws[i]:
		print(-1)
		exit(0)

a = []
vis = [False] * n
for i in range(n):
	if not vis[i]:
		a.append(0)
		j = i
		while not vis[j]:
			a[-1] += 1
			vis[j] = True
			j = w[j]

def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

ans = 1
for i in a:
	if i % 2 == 0:
		i //= 2
	ans = ans // gcd(ans, i) * i
print(ans)
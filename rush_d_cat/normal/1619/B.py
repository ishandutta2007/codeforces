eps = 1e-9
t = int(input())
for t in range(t):
	x = int(input())
	ans = int(x**(1.0/2) + eps) + int(x**(1.0/3) + eps) - int(x**(1.0/6) + eps)
	print(ans)
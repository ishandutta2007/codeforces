n, m, k = [int(x) for x in raw_input().split()]

if k > n + m - 2 :
	print -1
else :
	ans = 0
	i = 1
	while True :
		ans = max(ans, n / i * (m / (k + 2 - i)))
		if i == k + 1 or i == n :
			break
		i = min(n / (n / (i + 1)), k + 1)
	print ans
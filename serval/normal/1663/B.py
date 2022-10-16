s = [1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000]
n = int(input())
ans = 3000
for i in s:
	if i > n:
		ans = min(ans, i)
print(ans)
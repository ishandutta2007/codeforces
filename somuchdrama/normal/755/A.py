n = int(input())
def ispr(m):
	i = 2
	while i * i <= m:
		if m % i == 0:
			return False
		i += 1
	return True
for i in range(1, 1001):
	if not ispr(n * i + 1):
		print(i)
		exit(0)
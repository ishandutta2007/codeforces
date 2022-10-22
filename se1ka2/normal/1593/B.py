ob = ('52', '05', '57', '00')

t = int(input())
while t:
	t -= 1
	n = input()
	s = n[::-1]
	ans = 100000
	for o in ob:
		j = 0
		for i in range(len(s)):
			if s[i] == o[j]:
				j += 1
			if j == 2:
				ans = min(ans, i - 1)
				break
	print(ans)
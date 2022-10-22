t = int(input())
while t:
	t -= 1
	n = int(input())
	s = list(input().split())
	f = False
	ans = [s[0]]
	for i in range(1, n - 2):
		if s[i][0] != s[i - 1][1]:
			f = True
			ans.append(s[i])
		else:
			ans.append(s[i][1])
	if not f:
		ans.append('a')
	print(''.join(ans))
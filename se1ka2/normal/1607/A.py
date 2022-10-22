def nth(c):
	return ord(c) - ord('a')

t = int(input())
while t:
	t -= 1
	key = input()
	d = [0 for i in range(26)]
	for i in range(26):
		d[nth(key[i])] = i
	s = input()
	ans = 0
	for i in range(1, len(s)):
		ans += abs(d[nth(s[i])] - d[nth(s[i - 1])])
	print(ans)
t = int(input())
while t:
	t -= 1
	s = input()
	if s[0 : len(s) // 2] == s[len(s) // 2 : len(s)]:
		print("YES")
	else:
		print("NO")
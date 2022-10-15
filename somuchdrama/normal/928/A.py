def norm(s):
	return s.lower().replace('o', '0').replace('i', '1').replace('l', '1')

s = norm(input())
for i in range(int(input())):
	if norm(input()) == s:
		print("No")
		break
else:
	print("Yes")
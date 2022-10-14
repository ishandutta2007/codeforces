s = input()
cnt = 0
m=10**9 + 7
t = 0

for i in range(len(s)):
	if s[~i] == 'a':
		cnt = (cnt+t)%m
		t = (t*2)%m
	else:
		t += 1
print(cnt)
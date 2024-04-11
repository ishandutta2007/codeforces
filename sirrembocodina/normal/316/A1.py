s = input()
ans = 1
used = [False] * 10
fl = False
for i in range(len(s)):
	c = s[i]
	if c == '?':
		ans *= 10 if i else 9
		continue
	x = ord(c)
	if ord('0') <= x <= ord('9'):
		continue
	used[x - ord('A')] = True
	if i == 0:
		fl = True
cur = 10
for b in used:
	if b:
		ans *= cur
		cur -= 1
if fl:
	ans //= 10
	ans *= 9
print(ans)
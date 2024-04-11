n = int(input())
s = input()
out = True
ln = 0
ans1 = 0
ans2 = 0
for i in s:
	if i == '_':
		if out:
			ans1 = max(ans1, ln)
		else:
			if ln > 0:
				ans2 += 1
		ln = 0
	elif i in '()':
		if out:
			ans1 = max(ans1, ln)
		else:
			if ln > 0:
				ans2 += 1
		ln = 0
		out = not out
	else:
		ln += 1
if out:
	ans1 = max(ans1, ln)
else:
	if ln > 0:
		ans2 += 1
print(ans1, ans2)
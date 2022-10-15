s = input()
t = ""
for i in s:
	if i.isalpha():
		t += ' '
	else:
		t += i
a = t.split()
ans1 = 0
ans2 = 0
for i in a:
	b = i.split('.')
	part = None
	cur = 0
	for j in range(len(b)):
		if len(b[j]) == 2 and j > 0:
			part = int(b[j])
		else:
			cur *= 1000
			cur += int(b[j])
	if not (part is None):
		ans2 += part
	ans1 += cur
cnt = ans2 // 100
ans1 += cnt
ans2 -= cnt * 100
tmp = str(ans1)[::-1]
tmp2 = ""
for i in range(len(tmp)):
	tmp2 += tmp[i]
	if i % 3 == 2 and i != len(tmp) - 1:
		tmp2 += '.'
ans1 = tmp2[::-1]
if ans2 == 0:
	print(ans1)
else:
	ans2 = str(ans2)
	if len(ans2) == 1:
		ans2 = "0" + ans2
	print("%s.%s" % (ans1, ans2))
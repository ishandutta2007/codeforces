ch = raw_input()
ans = 0
preop = "+"
now = 0

for i in ch:
	if i.isdigit():
		now = now * 10 + ord(i) - 48
	else:
		if preop == "+":
			ans += now
		else:
			ans -= now
		preop = i
		now = ord(i) - 48

if preop == "+":
	ans += now
else:
	ans -= now
print ans
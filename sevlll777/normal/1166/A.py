sos=dict()
for i in range(int(input())):
	s = input()
	if s[0] not in sos:
		sos[s[0]] = 0
	sos[s[0]] += 1
cnt = 0
for i in sos:
	a = sos[i]
	cnt += ((a // 2) * (a // 2 - 1)) // 2
	a += 1
	cnt += ((a // 2) * (a // 2 - 1)) // 2
print(cnt)
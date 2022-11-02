n = int(raw_input())

if n < 3 :
	print -1
else :
	ans = 10 ** (n - 1) + 20
	while ans % 7 != 0 :
		ans += 30
	print ans
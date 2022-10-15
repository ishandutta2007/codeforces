x, of, t = input().split()
x = int(x)
if t == "month":
	if x < 30:
		print(12)
	elif x == 30:
		print(11)
	else:
		print(7)
else:
	if 7 > x > 4:
		print(53)
	else:
		print(52)
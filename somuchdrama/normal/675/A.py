a, b, c = map(int, input().split())
if c == 0:
	if a == b:
		print("YES")
	else:
		print("NO")
else:
	d, r = divmod(b - a, c)
	if a == b:
		print("YES")
	else:
		if d < 1 or r != 0:
			print("NO")
		else:
			print("YES")
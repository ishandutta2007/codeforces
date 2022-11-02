a, b, m = map(int, raw_input().split())
if a >= m or b >= m:
	print 0
else:
	if a <= 0 and b <= 0:
		print -1
	else:
		ans = 0
		if a <= 0:
			x = (-a) / b
			a += b * x
			ans = x
		if b <= 0:
			x = (-b) / a
			b += a * x
			ans = x
		while a < m and b < m:
			if a < b: a += b
			else: b += a
			ans += 1
		print ans
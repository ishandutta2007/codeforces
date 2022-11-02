a, b = [int(x) for x in raw_input().split()]

if a < b :
	print 0
elif a == b :
	print 'infinity'
else :
	i = 1
	ans = 0
	while i * i <= a - b :
		if (a - b) % i == 0 :
			if i > b :
				ans += 1
			if i * i != a - b and (a - b) / i > b :
				ans += 1
		i += 1
	print ans
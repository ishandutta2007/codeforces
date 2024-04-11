h, m = [int(i) for i in input().strip().split(':')]
t = h * 60 + m
for i in range(1440):
	a = str(t // 60)
	b = str(t % 60)
	if len(a) == 1:
		a = '0' + a
	if len(b) == 1:
		b = '0' + b
	c = b[1] + b[0]
	if a == c:
		print(i)
		exit(0)
	t = (t + 1) % 1440
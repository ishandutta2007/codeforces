a=str(eval(raw_input()))
for i in range(len(a)):
	b=">"
	for j in range(ord(a[i])):
		b=b+"+"
	print b+"."
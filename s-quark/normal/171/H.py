def f(a, b):
	#print a, b
	if(b == 0):
		return (0,0)
	x, y = f(a-1, b%(4**(a-1)))
	#print x, y
	if(b < 4**(a-1)):
		return (y, x)
	if(b < 2*4**(a-1)):
		return (x, y+2**(a-1))
	if(b < 3*4**(a-1)):
		return (x+2**(a-1), y+2**(a-1))
	return (2**a-1-y, 2**(a-1)-1-x)

a, b = raw_input().split()
a = int(a)
b = int(b)
a, b = f(a, b)
print a, b
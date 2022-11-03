n = input()
A, B, C = 1234567, 123456, 1234
ans = False
while not ans and n >= 0:
	n1 = n
	while not ans and n1 >= 0:
		ans |= n1 % C == 0
		n1 -= B
	n -= A
print "YES" if ans else "NO"
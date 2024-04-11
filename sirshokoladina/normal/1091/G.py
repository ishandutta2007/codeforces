import sys
from random import randint

def gcd(a, b):
	if a > 0:
		return gcd(b % a, a)
	return b

n = int(sys.stdin.readline())

a = [n]

for i in range(60):
	x = randint(1, n - 1)
	while gcd(x, n) > 1:
		x = randint(1, n - 1)
	print('sqrt', x * x % n)
	sys.stdout.flush()
	y = int(sys.stdin.readline())

	k = abs(x - y)
	b = []
	for m in a:
		d = gcd(m, k)
		if d > 1:
			b.append(d)
		if d < m:
			b.append(m // d)

	a = b

print('!', len(a), *a)
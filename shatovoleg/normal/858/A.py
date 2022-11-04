n, k = map(int, input().split())
k = 10 ** k

def gcd(a, b):
	while b:
		a, b = b, a % b
	return a

print(n // gcd(n, k) * k)
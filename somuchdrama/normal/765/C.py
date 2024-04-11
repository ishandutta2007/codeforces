k, a, b = map(int, input().split())
ca = a // k
cb = b // k
if ca * k != a and cb < 1 or cb * k != b and ca < 1:
	print(-1)
else:
	print(ca + cb)
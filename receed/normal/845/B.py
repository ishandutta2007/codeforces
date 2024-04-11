def f(x):
	return sum(x[:3]) == sum(x[3:])

def main():
	a = [int(i) for i in input()]
	if f(a):
		return 0
	for i in range(6):
		for j in range(10):
			b = a[:]
			b[i] = j
			if f(b):
				return 1
	for i in range(6):
		for j in range(i):
			for k in range(10):
				for l in range(10):
					b = a[:]
					b[i] = k
					b[j] = l
					if f(b):
						return 2
	return 3

print(main())
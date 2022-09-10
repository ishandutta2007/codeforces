t = int(input())

for _ in range(t):
	a, b = [int(x) for x in input().split()]
	d = b - a
	if a == b: 
		print(0)
	elif b > a and d % 2 == 1:
		 print(1)
	elif b > a and d % 2 == 0:
		 print(2)
	elif b < a and d % 2 == 0:
		 print(1)
	elif b < a and d % 2 == 1:
		 print(2)
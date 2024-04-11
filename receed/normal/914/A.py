n = int(input())
a = [int(i) for i in input().split()]
x = -10**7
for i in a:
	if i < 0 or round(i ** 0.5) ** 2 != i:
		x = max(x, i)
print(x)
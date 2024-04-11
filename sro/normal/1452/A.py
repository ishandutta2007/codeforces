read = lambda: map(int, input().split())
 
T = int(input())
 
for t in range(T):
	a, b = read()
	b = max(b, a - 1)
	a = max(a, b - 1)
	print(a + b)
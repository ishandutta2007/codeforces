def solve():
	n, m = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	pos = [int(x)-1 for x in input().split()]
	cut = set(range(0, n)) - set(pos)
	#print(cut)
	last = -1

	for c in cut:
		a[last+1:c+1] = sorted(a[last+1:c+1])
		last = c

	return a == sorted(a)

t = int(input())

for _ in range(t):
	if solve():
		print("YES")
	else:
		print("NO")
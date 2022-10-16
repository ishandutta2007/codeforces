def solve():
	l = int(input())
	n = int(input())
	for i in range(1, 10):
		v = int(str(i) * l)
		if len(str(v - n)) == l and v > n:
			print(v - n)
			return
		v = int(str(i) * (l + 1))
		if len(str(v - n)) == l and v > n:
			print(v - n)
			return

T = int(input())

for i in range(T):
	solve()
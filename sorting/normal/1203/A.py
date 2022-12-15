from sys import stdin, stdout

def cin():
	return stdin.readline().rstrip()
def cout(s):
	stdout.write(s)

def nxt(x, n):
	if x == n:
		return 1
	else:
		return x + 1

q = int(cin())

for _ in range(q):
	n = int(cin())
	a = [int(x) for x in cin().split()]

	ok = True
	for i in range(1, n):
		if a[i - 1] != nxt(a[i], n):
			ok = False
			break

	if ok and a[n - 1] == nxt(a[0], n):
		cout("YES\n")
		continue

	ok = True
	for i in range(1, n):
		if a[i] != nxt(a[i - 1], n):
			ok = False
			break

	if ok and a[0] == nxt(a[n - 1], n):
		cout("YES\n")
	else:
		cout("NO\n")

t = int(input())
for t in range(t):
	s = input()
	l = len(s)
	print('YES' if l % 2 == 0 and s[:l//2] == s[-l//2:] else 'NO')
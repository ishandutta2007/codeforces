n = int(input())
s = sum(list(map(int, input().split())))
m = int(input())
for i in range(m):
	l, r = map(int, input().split())
	s = max(s, l)
	if l <= s <= r:
		print(s)
		exit(0)
print(-1)
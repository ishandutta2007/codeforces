n, m = map(int, raw_input().split())

lst = {}
for x in map(int, raw_input().split()):
	lst[x] = 0

ans = []
s, i = 0, 1
while s <= m:
	if not lst.has_key(i):
		s += i
		ans.append(i)
	i += 1

print len(ans) - 1
for i in range(0, len(ans) - 1):
	print ans[i],
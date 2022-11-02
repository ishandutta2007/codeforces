from collections import defaultdict

n = int(raw_input())
d = defaultdict(lambda: 0)
for x in raw_input().split():
	if x != "0":
		d[x] += 1

ans = 0
fail = False
for x in d:
	if d[x] > 2:
		fail = True
	if d[x] == 2:
		ans += 1

print -1 if fail else ans
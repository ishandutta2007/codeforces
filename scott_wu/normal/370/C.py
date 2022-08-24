n, m = (int(s) for s in raw_input().split())

c = sorted ([int(s) for s in raw_input().split()])
d = c[n/2:] + c[:n/2]

tot = 0
for x, y in zip (c, d):
	tot += int (x != y)

print tot
for x, y in zip (c, d):
    print x, y
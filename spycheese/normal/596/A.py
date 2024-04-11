n = int(input())
a = [tuple(map(int, input().split())) for i in range(n)]

xmin = 100000
xmax = -100000
ymin = 100000
ymax = -100000

for b in a:
    xmin = min(xmin, b[0])
    xmax = max(xmax, b[0])
    ymin = min(ymin, b[1])
    ymax = max(ymax, b[1])

r = (xmax-xmin) * (ymax-ymin)
if r == 0:
    print(-1)
else:
    print(r)
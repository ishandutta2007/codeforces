n = 666
x, y = map(int, input().split())
L = [0]
for _ in range(n):
    a, b = map(int, input().split())
    L.append([a, b])
while (x, y) != (500, 500):
    if x < 500 and [x + 1, y] not in L:
        x += 1
    if x > 500 and [x - 1, y] not in L:
        x -= 1
    if y < 500 and [x, y + 1] not in L:
        y += 1
    if y > 500 and [x, y - 1] not in L:
        y -= 1

    print(x, y)
    k, a, b = map(int, input().split())
    if k <= 0:
        exit(0)
    L[k] = [a, b]
c1 = 0
c2 = 0
c3 = 0
c4 = 0
for a, b in L[1:]:
    if b > 500 > a:
        c1 += 1
    elif a < 500:
        c3 += 1
    elif b > 500:
        c2 += 1
    else:
        c4 += 1
m = min(c1, c2, c3, c4)
xx, yy = 0, 0
if c1 == m:
    xx, yy = 1, -1
elif c2 == m:
    xx, yy = -1, -1
elif c3 == m:
    xx, yy = 1, 1
else:
    xx, yy = -1, 1
while True:
    if [x+xx, y+yy] in L:
        f = 1
        for x2 in [-1, 0, 1]:
            for y2 in [-1, 0, 1]:
                if f and (x2 or y2) and [x+x2, y+y2] not in L and 1 <= x+x2 <= 999 and 1 <= y+y2 <= 999:
                    shah = 0
                    for a, b in L[1:]:
                        if a == x+x2 or b == y+y2:
                            shah = 1
                            break
                    if shah:
                        x += x2
                        y += y2
                        f = 0
                        break
    elif 1<=x+xx<=999 and 1<=y+yy<=999:
        x += xx
        y += yy
    else:
        x -= xx
        y -= yy
    print(x, y)
    k, a, b = map(int, input().split())
    if k <= 0:
        exit(0)
    L[k] = [a, b]
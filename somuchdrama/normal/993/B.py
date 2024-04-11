n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
can0 = set()
can1 = [set() for i in range(n)]
can2 = [set() for i in range(m)]

for i in range(n):
    for j in range(m):
        x1 = a[i * 2]
        x2 = a[i * 2 + 1]
        y1 = b[j * 2]
        y2 = b[j * 2 + 1]
        if x1 > x2: x1, x2 = x2, x1
        if y1 > y2: y1, y2 = y2, y1
        if x1 == y1 and x2 == y2: continue
        if x1 == y1:
            can1[i].add(y1)
            can2[j].add(y1)
            can0.add(y1)
        if x2 == y1:
            can1[i].add(y1)
            can2[j].add(y1)
            can0.add(y1)
        if x1 == y2:
            can1[i].add(y2)
            can2[j].add(y2)
            can0.add(y2)
        if x2 == y2:
            can1[i].add(y2)
            can2[j].add(y2)
            can0.add(y2)
if len(can0) == 1:
    print(min(can0))
else:
    ok = True
    for i in can1:
        if len(i) > 1:
            ok = False
    for i in can2:
        if len(i) > 1:
            ok = False
    if ok: print(0)
    else: print(-1)
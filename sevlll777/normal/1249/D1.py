from heapq import *
n, k = map(int, input().split())
E = []
opent = {}
clos = {}
for i in range(n):
    l, r = map(int, input().split())
    E.append([l, 1, i])
    E.append([r, -1, i])
    opent[i] = r
    clos[i] = l
E.sort(key=lambda x: (x[0], -x[1], -opent[x[2]]))
b = 0
now_r = []
heapify(now_r)
cnt_delet = 0
ans = []
deleted = set()
for x, t, i in E:
    if t == 1:
        heappush(now_r, -(opent[i] * 10 ** 6 + i))
    else:
        if i not in deleted:
            cnt_delet += 1
    if len(now_r) - cnt_delet > k:
        for _ in range(len(now_r) - cnt_delet - k):
            nm = heappop(now_r)
            ind = (-nm) % 10 ** 6
            ans.append(ind + 1)
            deleted.add(ind)
print(len(ans))
print(*ans)
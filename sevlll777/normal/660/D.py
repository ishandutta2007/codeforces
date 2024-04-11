n = int(input())
dc = {}
P = []
for i in range(n):
    x, y = map(int, input().split())
    P.append([x, y])
for i in range(n):
    for j in range(i + 1, n):
        x1, y1 = P[i]
        x2, y2 = P[j]
        if(x1+x2,y1+y2) not in dc:
            dc[(x1+x2, y1+y2)] = 0
        dc[(x1+x2,y1+y2)]+=1
ans = 0
for x in dc:
    ans += dc[x] * (dc[x] - 1)
print(ans // 2)
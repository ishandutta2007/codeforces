n = int(input())
T = []
for i in range(n):
    x, y = map(int, input().split())
    T.append([x, y])
P = []
for i in range(n):
    for j in range(i + 1, n):
        x1, y1 = T[i]
        x2, y2 = T[j]
        a = y2 - y1
        b = x1 - x2
        c = -(a * x1 + b * y1)
        P.append([a, b, c])
const = 10 ** 10 + 3
cnt = 0
newP = []
visit = []
for a, b, c in P:
    if a != 0:
        if [1, b / a, c / a] not in visit:
            newP.append([1, b / a, c / a])
            visit.append([1, b / a, c / a])
    else:
        if [0, 1, c / b] not in visit:
            newP.append([0, 1, c / b])
            visit.append([0, 1, c / b])
P = newP
for i in range(len(P)):
    for j in range(i + 1, len(P)):
        a1, b1, c1 = P[i]
        a2, b2, c2 = P[j]
        if a1 * b2 == a2 * b1:
            pass
        else:
            x = (b1 * c2 - b2 * c1) / (a1 * b2 - b1 * a2)
            y = (c1 * a2 - a1 * c2) / (a1 * b2 - b1 * a2)
            cnt += 1
print(cnt)
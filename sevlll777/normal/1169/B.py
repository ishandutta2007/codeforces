from copy import copy
n, m = map(int, input().split())
P = []
z = set()
for i in range(1, n + 1):
    z.add(i)
for i in range(m):
    P.append(list(map(int, input().split())))
for x in P[0][0], P[0][1]:
    s = copy(z)
    for i in range(1, m):
        a, b = P[i]
        if a != x and b != x:
            s.intersection_update({a, b})
    if len(s):
        print('YES')
        exit(0)
print('NO')
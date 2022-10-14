n, m, d = map(int, input().split())
d -= 1
C = list(map(int, input().split()))
h = n - sum(C)
kek = []
for i in range(m):
    if h >= d:
        kek += [0] * d + [i + 1] * C[i]
        h -= d
    else:
        kek += [0] * h + [i + 1] * C[i]
        h = 0
if h > d:
    print('NO')
else:
    kek += [0] * h
    print('YES')
    print(*kek)
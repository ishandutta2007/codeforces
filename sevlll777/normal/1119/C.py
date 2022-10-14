n, m = map(int, input().split())
A1 = [list(map(int, input().split())) for i in range(n)]
A2 = [list(map(int, input().split())) for wi in range(n)]
for i in range(n):
    if A1[i].count(0) % 2 != A2[i].count(0) % 2:
        print('No')
        exit(0)
for j in range(m):
    z1 = 0
    z2 = 0
    for i in range(n):
        if A1[i][j] == 0:
            z1 += 1
        if A2[i][j] == 0:
            z2 += 1
    if z1 % 2 != z2 % 2:
        print('No')
        exit(0)
print('Yes')
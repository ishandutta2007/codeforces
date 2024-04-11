n = int(input())
ks = [[0]]
for i in range(n):
    ks.append([i + 1])
for _ in range(n - 1):
    a, b = map(int, input().split())
    while type(ks[a]) == int:
        a = ks[a]
    while type(ks[b]) == int:
        b = ks[b]
    if len(ks[a]) >= len(ks[b]):
        ks[a] += ks[b]
        ks[b] = a
    else:
        ks[b] += ks[a]
        ks[a] = b
    if _ == n - 2:
        while type(ks[a]) == int:
            a = ks[a]
        print(*ks[a])
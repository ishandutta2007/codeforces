n = int(input())
gr = {i: 0 for i in range(1, n + 1)}
for i in range(n - 1):
    a, b = map(int, input().split())
    gr[a] += 1
    gr[b] += 1
for i in gr:
    if gr[i] == 2:
        print('NO')
        exit(0)
print('YES')
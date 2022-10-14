n = int(input())
S = []
for i in range(n):
    l, r = map(int, input().split())
    S.append([l, r, i + 1])
S.sort(key=lambda x: (x[1], -x[0]))
for i in range(n - 1):
    l2, r2, j2 = S[i]
    l1, r1, j1 = S[i + 1]
    if l1 <= l2 and r1 >= r2:
        print(j2, j1)
        exit(0)
print(-1, -1)
n, m = map(int, input().split())
A = [list(input()) for _ in range(n)]
f = {'f', 'a', 'c', 'e'}
cnt = 0
for i in range(n - 1):
    for j in range(m - 1):
        s = {A[i][j], A[i][j + 1], A[i + 1][j], A[i + 1][j + 1]}
        if s == f:
            cnt += 1
print(cnt)
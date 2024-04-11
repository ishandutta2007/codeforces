n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]
B = [[0] * m for _ in range(n)]
ans = []
for i in range(n - 1):
    for j in range(m - 1):
        if A[i][j] == 1 and A[i + 1][j] == 1 and A[i][j + 1] == 1 and A[i + 1][j + 1] == 1:
            B[i][j] = 1
            B[i + 1][j] = 1
            B[i][j + 1] = 1
            B[i + 1][j + 1] = 1
            ans.append([i + 1, j + 1])
if A == B:
    print(len(ans))
    for a, b in ans:
        print(a, b)
else:
    print(-1)
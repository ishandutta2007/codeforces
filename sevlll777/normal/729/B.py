n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]
B = [[0] * (m + 1)]
for c in A:
    B.append([0] + c)
for i in range(1, n + 1):
    for j in range(1, m + 1):
        B[i][j] += B[i][j-1] + B[i-1][j] - B[i-1][j-1]
cnt = 0
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if A[i-1][j-1] == 0:
            if B[i][j] - B[i-1][j]:
                cnt += 1
            if (B[i][m] - B[i][j-1] - B[i-1][m] + B[i-1][j-1]):
                cnt+=1
            if B[i][j] - B[i][j-1]:
                cnt += 1
            if B[n][j] - B[i-1][j] - B[n][j-1] + B[i-1][j-1]:
                cnt += 1
print(cnt)
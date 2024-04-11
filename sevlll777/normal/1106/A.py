n = int(input())
A = [list(input()) for i in range(n)]
cnt = 0
for i in range(1, n-1):
    for j in range(1, n-1):
        if A[i][j] == 'X' == A[i - 1][j - 1] == A[i + 1][j - 1] == A[i + 1][j + 1] == A[i - 1][j + 1]:
            cnt += 1
print(cnt)
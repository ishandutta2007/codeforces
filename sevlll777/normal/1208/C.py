n = int(input())
A = [[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        A[i][j] = (i % 4) * 4 + (j % 4) + (i // 4) * 4 * n + (j // 4) * 16
for u in A:
    print(*u)
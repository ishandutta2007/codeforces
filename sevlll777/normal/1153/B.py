n, m, h = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
H = [list(map(int, input().split())) for i in range(n)]
for i in range(n):
    for j in range(m):
        if H[i][j] == 1:
            H[i][j] = min(A[j], B[i])
for s in H:
    print(*s)
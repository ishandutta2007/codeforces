n, k = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = []
for i in range(n):
    C.append((A[i] - B[i], i))
C.sort()
ans = 0
for i in range(k):
    ans += A[C[i][1]]
g = n
for i in range(k, n):
    if C[i][0] <= 0:
        ans += A[C[i][1]]
    else:
        g = i
        break
for j in range(g, n):
    ans += B[C[j][1]]
print(ans)
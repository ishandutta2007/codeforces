n, k = map(int, input().split())
A = list(map(int, input().split()))
B = []
for i in range(n - 1):
    B.append([A[i + 1] - A[i], i])
B.sort(reverse=True)
C = []
for i in range(k - 1):
    C.append(B[i][1])
C.sort()
ans = 0
mi = 10 ** 9
ma = -10 ** 9
u = 0
for i in range(n):
    mi = min(mi, A[i])
    ma = max(ma, A[i])
    if u < len(C) and i == C[u]:
        ans += ma - mi
        mi = 10 ** 9
        ma = -10 ** 9
        u += 1
print(ans + ma - mi)
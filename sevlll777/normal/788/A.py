n = int(input())
A = list(map(int, input().split()))
B = []
for i in range(n - 1):
    B.append(abs(A[i] - A[i + 1]))
dpmin = [0] * n
dpmax = [0] * n
for i in range(n - 2, -1, -1):
    dpmax[i] = B[i]
    dpmin[i] = B[i]
    dpmin[i] = min(dpmin[i], B[i] - dpmax[i + 1])
    dpmax[i] = max(dpmax[i], B[i] - dpmin[i + 1])
print(max(dpmax))
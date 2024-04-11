n = int(input())
A = list(map(int, input().split()))
k = 10 ** 10
for i in range(1, n - 1):
    k = min(k, min(A[0], A[i]) // i)
    k = min(k, min(A[-1], A[i]) // (n - i - 1))
k = min(k, min(A[0], A[-1]) // (n - 1))
print(k)
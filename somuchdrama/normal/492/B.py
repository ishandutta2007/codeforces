n, m = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
a = A[0]
c = m - A[-1]
b = 0
for i in range(n - 1):
    if A[i + 1] - A[i] > b:
        b = A[i + 1] - A[i]
print(max(a, b / 2, c))
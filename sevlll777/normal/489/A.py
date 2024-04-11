n = int(input())
A = list(map(int, input().split()))
print(n - 1)
for i in range(n - 1):
    j = i + A[i:].index(min(A[i:]))
    print(i, j)
    A[i], A[j] = A[j], A[i]
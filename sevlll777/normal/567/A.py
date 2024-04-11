n = int(input())
A = list(map(int, input().split()))
print(A[1] - A[0], A[-1] - A[0])
for x in range(1, n - 1):
    i = A[x]
    print(min(i - A[x - 1], A[x + 1] - i), max(i - A[0], A[-1] - i))
print(A[-1] - A[-2], A[-1] - A[0])
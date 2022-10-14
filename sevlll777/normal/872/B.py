n, k = map(int, input().split())
A = list(map(int, input().split()))
if k >= 3:
    print(max(A))
    exit(0)
if k == 1:
    print(min(A))
    exit(0)
print(max(A[0], A[-1]))
n = int(input())
A = list(map(int, input().split()))
if n == 1 or (n == 2 and A[0] == A[1]):
    print(-1)
else:
    print(1)
    print(A.index(min(A)) + 1)
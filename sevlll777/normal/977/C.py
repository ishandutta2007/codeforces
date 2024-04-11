n, k = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
A.append(-1)
if k != 0:
    if A[k - 1] != A[k]:
        print(A[k-1])
    else:
        print(-1)
else:
    if A[0] == 1:
        print(-1)
    else:
        print(A[0] - 1)
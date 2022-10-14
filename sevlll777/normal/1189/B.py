n = int(input())
A = list(map(int, input().split()))
A.sort()
if A[-1] >= A[-2] + A[-3]:
    print('NO')
else:
    print('YES')
    print(A[-2], A[-1], A[-3], *A[:-3])
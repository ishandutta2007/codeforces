n = int(input())
A = list(map(int, input().split()))
if n == 1:
    if A[0] >= 0:
        print(A[0])
    else:
        print(-A[0]-1)
    exit(0)
for i in range(n):
    if A[i] < 0:
        pass
    else:
        A[i] = -A[i]-1
if n % 2 == 0:
    print(*A)
    exit(0)
mim = 0
indmim = 0
for i in range(n):
    if A[i] < mim:
        mim = A[i]
        indmim = i
A[indmim] = -A[indmim]-1
print(*A)
n, x = map(int, input().split())
A = []
B = []
for i in range(n):
    a, b = map(int, input().split())
    A.append(min(a, b))
    B.append(max(a, b))
R = []
for i in range(min(A), max(B) + 1):
    res = abs(x - i)
    for j in range(n):
        if A[j] <= i <= B[j]:
            pass
        else:
            res = 1001
            break
    R.append(res)
##print(R)
if min(R) == 1001:
    print(-1)
else:
    print(min(R))
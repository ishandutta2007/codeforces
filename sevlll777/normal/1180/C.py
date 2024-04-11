from collections import deque
n, q = map(int, input().split())
A = deque(list(map(int, input().split())))
z = max(A)
f = 0
B = []
C = []
for i in A:
    if f:
        C.append(i)
    else:
        if i == z:
            f = 1
ans = []
while A[0] != z:
    B.append(min(A[0], A[1]))
    ans.append([A[0], A[1]])
    if A[0] > A[1]:
        x = A[0]
        y = A[1]
        A.popleft()
        A[0] = x
        A.append(y)
    else:
        x = A[0]
        A.popleft()
        A.append(x)
C += B
j = len(ans)
for i in range(q):
    x = int(input())
    if x <= j:
        print(ans[x - 1][0], ans[x - 1][1])
    else:
        x -= j
        x %= (n - 1)
        print(z, C[x - 1])
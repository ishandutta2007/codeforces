n = int(input())
A = list(map(int, input().split()))
A.sort()
if len(A) > 1:
    B = [A[0], A[1]]
else:
    B = [A[0]]
for i in range(n - 2):
    if A[i] != A[i + 2]:
        B.append(A[i + 2])
if len(A) > 1 and A[-1] == A[-2]:
    B.pop()
print(len(B))
P, Q = [], []
for i in range(len(B) - 1, -1, -1):
    if i % 2:
        P.append(B[i])
    else:
        Q.append(B[i])
print(*P[::-1], *Q)
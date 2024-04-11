n = int(input())
A = list(map(int, input().split()))
B = [1]
su = A[0]
for i in range(1, n):
    if A[0] >= 2 * A[i]:
        B.append(i + 1)
        su += A[i]
if su * 2 > sum(A):
    print(len(B))
    print(*B)
else:
    print(0)
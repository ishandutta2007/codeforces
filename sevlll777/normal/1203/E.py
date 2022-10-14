n = int(input())
A = list(map(int, input().split()))
A.sort()
if A[0] != 1:
    A[0] -= 1
A[-1] += 1
for i in range(1, n - 1):
    if A[i] - 1 > A[i - 1] and A[i] != 1:
        A[i] -= 1
    elif A[i] == A[i - 1] and A[i] != A[i + 1]:
        A[i] += 1
print(len(set(A)))
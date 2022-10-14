A = list(map(int, input().split()))
A.sort()
ans = sum(A)
for i in range(4, 1, -1):
    if A[i] == A[i - 1] == A[i - 2]:
        ans = min(ans, sum(A) - 3 * A[i])
for i in range(4, 0, -1):
    if A[i] == A[i - 1]:
        ans = min(ans, sum(A) - 2 * A[i])
print(ans)
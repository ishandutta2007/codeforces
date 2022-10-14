n = int(input())
A = list(map(int, input().split()))
A.sort()
ans = 0
for i in range(1, n):
    if A[i] <= A[i - 1]:
        ans += A[i - 1] - A[i] + 1
        A[i] = A[i - 1] + 1
print(ans)
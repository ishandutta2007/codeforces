n = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(1, n):
    if A[i] != A[0]:
        ans = max(ans, i)
for i in range(n - 1):
    if A[i] != A[-1]:
        ans = max(ans, n - i - 1)
print(ans)
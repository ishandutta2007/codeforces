from bisect import bisect_right
n, d = map(int, input().split())
A = list(map(int, input().split()))
ans = 0
for i in range(n):
    j = bisect_right(A, A[i] + d) - 1
    ans += (j - i) * (j - i - 1) // 2
print(ans)
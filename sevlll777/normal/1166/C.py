from bisect import bisect_right
n = int(input())
A = list(map(int, input().split()))
for i in range(len(A)):
    A[i] = abs(A[i])
A.sort()
cnt = 0
for i in range(len(A)):
    q = 2 * A[i]
    j = bisect_right(A, q)
    cnt += max(0, j - i - 1)
print(cnt)
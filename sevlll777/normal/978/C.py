from bisect import bisect_right
n, m = map(int, input().split())
A = list(map(int, input().split()))
for t in range(1, len(A)):
    A[t] += A[t - 1]
P = list(map(int, input().split()))
for t in P:
    k = bisect_right(A, t)
    if A[0] >= t:
        print(1, t)
    elif A[k - 1] == t:
        print(k, A[k - 1] - A[k - 2])
    else:
        print(k + 1, t - A[k - 1])
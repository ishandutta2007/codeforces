from copy import copy
n, m = map(int, input().split())
T = list(map(int, input().split()))
Z = copy(T)
for i in range(1, n):
    Z[i] += Z[i - 1]
for i in range(n):
    if Z[i] <= m:
        print(0, end=' ')
    else:
        A = T[:i]
        A.sort()
        s = 0
        for j in range(len(A)):
            s += A[j]
            if s > m - T[i]:
                print(len(A) - j, end=' ')
                break
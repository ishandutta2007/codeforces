n, m, k = map(int, input().split())
A = list(map(int, input().split()))
A.sort(reverse=True)
if m < k:
    print(A[0] * m)
else:
    k += 1
    print(A[0] * (m - m // k) + A[1] * (m // k))
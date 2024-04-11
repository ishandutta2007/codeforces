n, m = map(int, input().split())
A = list(map(int, input().split()))
s = sum(A)
if n == 1:
    print(0)
else:
    ans = 0
    A.sort(reverse=True)
    for i in range(n - 1):
        A[i] = min(A[i], m)
        if A[i] > A[i + 1]:
            ans += A[i] - A[i + 1]
            m = min(m, A[i + 1])
        else:
            ans += 1
            m = max(1, min(m, A[i] - 1))
    ans += m
    print(s - ans)
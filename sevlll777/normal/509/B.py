n, k = map(int, input().split())
A = list(map(int, input().split()))
m = min(A)
ma = max(A)
if ma - (m - m % k) > k + m % k:
    print('NO')
else:
    B = [i for i in range(1, k + 1)] * 1000
    print('YES')
    for i in A:
        print(*B[:i])
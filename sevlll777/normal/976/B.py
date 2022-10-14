n, m, k = map(int, input().split())
if k < n:
    print(k + 1, 1)
elif k < n + m - 1:
    print(n, k - n + 2)
else:
    k -= (n + m - 1)
    x = n - (k // (m - 1)) - 1
    if (k // (m - 1)) % 2 == 0:
        y = m - k % (m - 1)
    else:
        y = k % (m - 1) + 2
    print(x, y)
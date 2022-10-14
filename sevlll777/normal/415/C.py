n, k = map(int, input().split())
if n // 2 > k:
    print(-1)
elif n == 1 and k != 0:
    print(-1)
elif n == 1 and k == 0:
    print(1)
else:
    a = n // 2 - 1
    for i in range(1, a + 1):
        print(2 * i - 1, 2 * i, end=' ')
    print((k - a) * 3 + 4 * a - (4 * a) % (k - a), 4 * a - (4 * a) % (k - a) + (k - a) * 4, end=' ')
    if n % 2:
        print(998244353)
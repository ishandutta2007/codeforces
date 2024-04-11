n, k = map(int, input().split())
for i in range(1, n + 1):
    a, b = 2 * i - 1, 2 * i
    if k:
        print(b, a, end=' ')
        k -= 1
    else:
        print(a, b, end=' ')
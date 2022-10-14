for q in range(int(input())):
    k, n, a, b = map(int, input().split())
    if k <= n * b:
        print(-1)
    else:
        l = 0
        r = 10 ** 9
        while l + 1 < r:
            x = (l + r) // 2
            if (k - x * a - 1) // b + x >= n:
                l = x
            else:
                r = x
        print(min(n, l))
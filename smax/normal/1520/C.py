for _ in range(int(input())):
    n = int(input())
    if n == 2:
        print(-1)
        continue
    ret = [[0 for i in range(n)] for j in range(n)]
    num = 1
    for i in range(n):
        ret[i][n-1-i] = num
        num += 1
    f = True
    l = n - 2
    r = n
    while l >= 0 or r <= 2 * n - 2:
        if f:
            a = max(l - n + 1, 0)
            b = min(l, n - 1)
            for i in range(a, b + 1):
                ret[i][l-i] = num
                num += 1
            l -= 1
        else:
            a = max(r - n + 1, 0)
            b = min(r, n - 1)
            for i in range(a, b + 1):
                ret[i][r-i] = num
                num += 1
            r += 1
        f = not f
    for i in range(n):
        print(' '.join(str(j) for j in ret[i]))
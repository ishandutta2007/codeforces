a, b, n = map(int, input().split())
if b < 10:
    n -= 1
    for c in range(9, -1, -1):
        if (10 * a + c) % b == 0:
            a = 10 * a + c
            break
    a = str(a)
    a += str(b) * n
    print(a)
else:
    n -= 1
    f = 0
    for c in range(9, -1, -1):
        if (10 * a + c) % b == 0:
            a = 10 * a + c
            f = 1
            break
    if not f:
        if n == 0:
            print(-1)
        else:
            print(-1)
    else:
        print(str(a) + '0' * n)
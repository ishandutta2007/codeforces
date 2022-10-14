n, a, x, b, y = map(int, input().split())
d = a
v = b
while d != -1 or v != -2:
    if d == v:
        print('YES')
        exit(0)
    if d != x and d != -1:
        d += 1
        d %= n
        if d == 0:
            d = n
    else:
        d = -1
    if v != y and v != -2:
        v -= 1
        if v == 0:
            v = n
    else:
        v = -2
    if d == v:
        print('YES')
        exit(0)
if d != v:
    print('NO')
else:
    print('YES')
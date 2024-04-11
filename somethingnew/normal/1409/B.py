def solve():
    a,b,x,y,n = map(int,input().split())
    if a >= b:
        y,x = x,y
        a,b = b,a
    if a - x + b - y <= n:
        print(x * y)
        return 0
    zn = a * b
    if a - x <= n:
        zn = min(zn, x * (b - (n - a + x)))
    else:
        zn = min(zn, (a - n) * b)
    if b - y <= n:
        zn = min(zn, y * (a - (n - b + y)))
    else:
        zn = min(zn, (b - n) * a)
    print(zn)
for i in range(int(input())):
    solve()
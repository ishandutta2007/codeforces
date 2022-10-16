def T():
    x,y,p,q = (int(z) for z in input().split())
    ost = (q - y % q) % q
    if p == q:
        if x == y:
            print(0)
        else:
            print(-1)
        return 0
    if p == 0:
        if x == 0:
            print(0)
        else:
            print(-1)
        return 0
    r, l = 10 ** 20, -1   
    while r - l > 1:
        eee = (l + r) // 2
        m = eee * q + ost
        if ((x + m) * q >= (y + m) * p and x * q <= (y+m)*p):
            r = eee
        else:
            l = eee
    print(int(r * q + ost))

t = int(input())
for i in range(t):
    T()
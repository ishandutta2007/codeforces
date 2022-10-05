def solve():
    p, f = map(int,input().split())
    cnts, cntw = map(int,input().split())
    s, w = map(int,input().split())
    if s > w:
        s, w = w, s
        cnts, cntw = cntw, cnts
    mans = 0
    for i in range(cnts + 1):
        ans = 0
        if p >= s * i:
            ans += i
            cntsnow = cnts - i
            pnow = p - s * i
            ans += min(cntw, pnow // w)
            cntwnow = cntw - min(cntw, pnow // w)
        fn = f
        ans += min(fn // s, cntsnow)
        fn -= min(fn // s, cntsnow) * s
        ans += min(fn // w, cntwnow)
        mans = max(ans, mans)
    print(mans)

for i in range(int(input())):
    solve()
for _ in range(int(input())):
    p, f = map(int, input().split())
    cnts, cntw = map(int, input().split())
    s, w = map(int, input().split())
    if s > w:
        s, w = w, s
        cntw, cnts = cnts, cntw
    kek = p // s + f // s
    if kek <= cnts:
        print(kek)
    else:
        ans = cnts
        for sk in range(cnts+1):
            p2, f2 = p, f
            p2 -= sk*s
            f2 -= (cnts-sk)*s
            if p2 >= 0 and f2 >= 0:
                ans = max(ans, cnts + p2 // w + f2 // w)
        ans = min(ans, cnts + cntw)
        print(ans)
n, m, l, r = map(int, input().split())
M = 998244353
f = n * m
if f % 2 == 1:
    print(pow(r-l+1,f,M))
elif l % 2 != r % 2:
    ev = r // 2 - (l - 1) // 2
    ans = pow(ev, f, M) * (pow(2, f - 1, M)) % M
    print(ans % M)
else:
    if l == r:
        print(1)
    else:
        ev = r // 2 - (l - 1) // 2
        od = (r - l + 1) - ev
        if od == ev + 1:
            if f % 2 == 0:
                SUM = pow(2 * ev + 1, f, M)
                DIF = 1
                nds = (SUM + DIF) * pow(2, M - 2, M) % M
                print(nds % M)
            else:
                SUM = pow(2 * ev + 1, f, M)
                print(SUM % M)
        else:
            if f % 2 == 0:
                SUM = pow(2 * ev - 1, f, M)
                DIF = 1
                nds = (SUM + DIF) * pow(2, M - 2, M) % M
                print(nds % M)
            else:
                SUM = pow(2 * ev - 1, f, M)
                print(SUM % M)
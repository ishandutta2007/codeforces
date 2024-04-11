from math import sqrt, gcd
def solve():
    m,d,w = map(int,input().split())
    if d == 1:
        print(0)
        return 0
    k = gcd(d-1,w)
    ww = w // k
    dd = min(m,d)
    qq = dd // ww
    res = + dd * qq - (qq + 1) * qq * ww // 2
    print(res)
for i in range(int(input())):
    solve()
def inter(l1, r1, l2, r2):
    l = max(l1,l2)
    r = min(r1,r2)
    return max(r - l, 0)
def solve():
    n, k = map(int,input().split())
    al, ar = map(int,input().split())
    bl, br = map(int,input().split())
    res = inter(al,ar,bl,br) * n
    goodt = max(ar, br) - min(al,bl) - inter(al,ar,bl,br)
    minhodi = 1000000000000
    hodi = 0
    to_soed = max(0, max(al,bl) - min(ar, br))
    if res >= k:
        print(0)
        return 0
    for i in range(n):
        hodi += to_soed
        ineed = k - res
        if goodt >= ineed:
            hodi += ineed
            minhodi = min(minhodi, hodi)
            break
        hodi += goodt
        res += goodt
        minhodi = min(hodi + (k - res) * 2, minhodi)
    print(minhodi)
for i in range(int(input())):
    solve()
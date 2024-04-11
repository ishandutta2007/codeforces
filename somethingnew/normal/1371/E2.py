def ican(a, x):
    k = x
    wr = 0
    for i in range(len(a)):
        if a[i] <= k:
            wr += 1
        else:
            wr -= a[i] - k
            k = a[i]
            if wr < 0:
                return False
            wr += 1
    return True
def bnpleft(a):
    r = max(a)
    l = -1
    while r - l > 1:
        h = (r+l)//2
        if ican(a, h): r = h
        else: l = h
    return l
def fa(a, x, p):
    k = x
    wr = 0
    for i in range(len(a)):
        if a[i] <= k:
            wr += 1
        else:
            nk = wr // p * p
            wr -= a[i] - k
            if wr < nk:
                return False
            k = a[i]
            if wr < 0:
                return False
            wr += 1
    if wr >= p:
        return False
    else:
        return True

def bnpr(a,p,left):
    l = left
    r = max(a)
    while r - l > 1:
        h = (r+l)//2
        if fa(a, h, p): l = h
        else: r = h
    return l
def solve():
    n, p = map(int, input().split())
    lst = list(map(int,input().split()))
    lst.sort()
    ll = bnpleft(lst)
    rr = bnpr(lst,p,ll)
    print(rr-ll)
    for i in range(ll + 1, rr + 1):
        print(i, end=" ")
for i in range(1):
    solve()
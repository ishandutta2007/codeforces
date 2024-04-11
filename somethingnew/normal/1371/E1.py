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
def solve():
    n, p = map(int, input().split())
    lst = list(map(int,input().split()))
    lst.sort()
    ans = []
    for x in range(max(max(lst) + 1, p + 1)):
        if fa(lst,x,p):
            ans.append(x)
    print(len(ans))
    print(*ans)
for i in range(1):
    solve()
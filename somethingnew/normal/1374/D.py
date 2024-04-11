def solve():
    n, k = map(int,input().split())
    lst = list(map(int,input().split()))
    lst2 = [lst[i] % k for i in range(n)]
    lst2.sort()
    lastelem = -1
    colvo = 0
    mxcolvo = 0
    mxnum = 0
    for i in lst2:
        if i == 0:
            continue
        if lastelem == i:
            colvo += 1
        else:
            if mxcolvo == colvo:
                mxnum = max((mxnum, (k - lastelem) % k))
            if mxcolvo < colvo:
                mxcolvo = colvo
                mxnum = (k - lastelem) % k
            colvo = 1
        lastelem = i
    if mxcolvo == colvo:
        mxnum = max(mxnum, (k - lastelem) % k)
    if mxcolvo < colvo:
        mxcolvo = colvo
        mxnum = (k - lastelem) % k
    print(max(mxcolvo * k - k + mxnum + 1, 0))
for i in range(int(input())):
    solve()
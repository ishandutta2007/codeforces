def solve():
    n, x = map(int,input().split())
    lst = list(map(int,input().split()))
    fp = -1
    lp = -1
    sm = 0
    for i in range(n):
        sm += lst[i]
        sm %= x
        if lst[i] % x != 0:
            if fp == -1:
                fp = i
            lp = i
    if sm:
        print(n)
    else:
        if fp == -1 and lp == -1:
            print(-1)
        elif fp == -1:
            print(lp)
        elif lp == -1:
            print(n - fp - 1)
        else:
            print(max(n - fp - 1, lp))
for t in range(int(input())):
    solve()
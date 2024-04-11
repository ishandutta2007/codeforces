def solve():
    n, k = map(int,input().split())
    a1 = []
    b1 = []
    ab1 = []
    for i in range(n):
        t,a,b = map(int,input().split())
        if a == 1 and b == 1:
            ab1.append(t)
        elif a == 1:
            a1.append(t)
        elif b == 1:
            b1.append(t)
    a1.sort()
    b1.sort()
    for i in range(min(len(a1),len(b1))):
        ab1.append(a1[i]+b1[i])
    ab1.sort()
    p = 0
    qq = len(ab1)
    if qq < k:
        print(-1)
    else:
        ans = 0
        for i in range(k): ans += ab1[i]
        print(ans)
for i in range(1):
    solve()
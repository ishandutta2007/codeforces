def solve():
    n, m = map(int,input().split())
    k = n + m - 1
    dd = [[] for i in range(k)]
    tb = [list(map(int,input().split())) for i in range(n)]
    for x in range(n):
        for y in range(m):
            dd[x+y].append(tb[x][y])
    ans = 0
    for i in range(k//2):
        n1 = len(dd[i]) + len(dd[k-i-1])
        n2 = sum(dd[i]) + sum(dd[k-i-1])
        ans += min(n2, n1-n2)
    print(ans)
for i in range(int(input())):
    solve()
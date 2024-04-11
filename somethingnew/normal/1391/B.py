def solve():
    n, m = map(int,input().split())
    lst = [list(input()) for i in range(n)]
    res = 0
    for x in range(n-1):
        if lst[x][m-1] == "R":
            res += 1
    for y in range(m-1):
        if lst[n-1][y] == "D":
            res += 1
    print(res)
for i in range(int(input())):
    solve()
def sosedi(x,y,n,m):
    s = 4
    if x == 0:
        s -= 1
    if x == n - 1:
        s -= 1
    if y == 0:
        s -= 1
    if y == m - 1:
        s -= 1
    return s

def solve():
    n, m = map(int,input().split())
    lst = [list(map(int,input().split())) for i in range(n)]
    for x in range(n):
        for y in range(m):
            if sosedi(x,y,n,m) < lst[x][y]:
                print("NO")
                return 
            lst[x][y] = sosedi(x,y,n,m)
    print("YES")
    for i in lst:
        print(*i)
for i in range(int(input())):
    solve()
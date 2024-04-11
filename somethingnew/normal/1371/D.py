def fa(ll, nn):
    an1 = 0
    an2 = 0
    k = nn
    for i in range(k):
        an1 += ll[i][0]
        an2 += ll[i][k - 1]
    print((an2-an1)**2*2)
def pr(j):
    fa(j, len(j))
    for i in j:
        print(*i, sep='')
def solve():
    n, k = map(int,input().split())
    lst = [[0 for i in range(n)] for j in range(n)]
    for y in range(n):
        for x in range(n):
            if k == 0:
                pr(lst)
                return
            lst[(y+x)%n][x] = 1
            k -= 1
    pr(lst)
for i in range(int(input())):
    solve()
def solve():
    n = int(input())
    dct = {}
    for i in list(map(int,input().split())):
        dct[i] = dct.get(i, 0) + 1
    maxnum = 0
    maxcl = 0
    for i in dct.values():
        if i == maxnum:
            maxcl += 1
        if i > maxnum:
            maxnum = i
            maxcl = 1
    print((n - maxnum - maxcl + 1) // (maxnum - 1))
for i in range(int(input())):
    solve()
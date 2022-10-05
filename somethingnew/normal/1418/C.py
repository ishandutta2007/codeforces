def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    if n == 1:
        print(lst[0])
        return 0
    dpi = [-1 for i in range(n)]
    dpdrug = [-1 for i in range(n)]
    dpi[n-1] = 0
    dpdrug[n-1] = lst[n-1]
    dpi[n-2] = 0
    dpdrug[n-2] = lst[n-2]
    for i in range(n-3,-1,-1):
        dpi[i] = min(dpdrug[i + 2], dpdrug[i + 1])
        dpdrug[i] = min(dpi[i + 1] + lst[i], dpi[i + 2] + lst[i] + lst[i + 1])
    print(dpdrug[0])
for i in range(int(input())):
    solve()
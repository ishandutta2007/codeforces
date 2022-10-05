def solve():
    n = int(input())
    a = list(map(int,input().split()))
    n1 = []
    n2 = []
    for i in range(0, n-1,2):
        n1.append(a[i+1] - a[i])
    for i in range(1, n-1, 2):
        n2.append(a[i]-a[i+1])
    ans = 0
    dopans = 0
    for i in range(n):
        if i %2:
            pass
        else:
            dopans += a[i]
    if len(n1):
        dp1 = [0 for i in range(len(n1))]
        dp1[0] = max(n1[0], 0)
        for i in range(1, len(n1)):
            dp1[i] = max(0, dp1[i-1] + n1[i])
    else:
        dp1 = [0]
    if len(n2):
        dp2 = [0 for i in range(len(n2))]
        dp2[0] = max(n2[0], 0)
        for i in range(1, len(n2)):
            dp2[i] = max(0, dp2[i - 1] + n2[i])
    else:
        dp2 = [0]
    print(dopans + max(max(dp1), max(dp2)))
for i in range(int(input())):
    solve()
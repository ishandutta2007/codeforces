def solve():
    n,h,l,r = map(int,input().split())
    a = list(map(int,input().split()))
    dp = [[-1 for i in range(h)] for i in range(n + 1)]
    dp[0][0] = 0
    for i in range(n):
        for k in range(h):
            if dp[i][k] != -1:
                dp[i+1][(k + a[i])%h] = max(dp[i+1][(k + a[i])%h],dp[i][k] + (l <= (k + a[i])%h <= r))
                dp[i + 1][(k + a[i]-1) % h] = max(dp[i + 1][(k + a[i]-1) % h], dp[i][k] + (l <= (k + a[i]-1) % h <= r))
    print(max(dp[n]))
for i in range(1):
    solve()
N=2*(10**5)+57
INF=10**10
dp=[[INF]*N,[INF]*N]
n,c=(int(z) for z in input().split())
dp[0][0]=0
dp[1][0]=c
a=[int(z) for z in input().split()]
b=[int(z) for z in input().split()]
for i in range(1,n):
    dp[0][i]=min(dp[0][i-1]+a[i-1], dp[1][i-1]+b[i-1])
    dp[1][i]=min(dp[0][i]+c, dp[1][i-1]+b[i-1])
for i in range(n):
    print(dp[0][i],end=' ')
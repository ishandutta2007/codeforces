from sys import *
	
MAXN=10**5+228
MOD=10**9+7

t,k=(int(z) for z in stdin.readline().split())
dp=[0]*MAXN
dp[0]=1
for i in range(1,MAXN):
    if i>=k:
        dp[i]=dp[i-k]+dp[i-1]
    else:
        dp[i]=dp[i-1]
    dp[i]%=MOD
for i in range(1,MAXN):
    dp[i]+=dp[i-1]
    dp[i]%=MOD
for i in range(t):
    a,b=(int(z) for z in stdin.readline().split())
    ans=(dp[b]-dp[a-1]+MOD)%MOD
    stdout.write(str(ans)+"\n")
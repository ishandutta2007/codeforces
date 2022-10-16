from math import *
from sys import *
from decimal import *

n=int(input())
r=[int(z) for z in input().split()]
dp=[[322]*n]
dp.append([322]*n)
dp.append([322]*n)
#print(dp)
if r[0]==3:
    dp[0][0]=0
    dp[1][0]=0
    dp[2][0]=1
if r[0]==1:
    dp[0][0]=0
    #dp[0][1]=0
    dp[2][0]=1
if r[0]==2:
    #dp[0][0]=0
    dp[1][0]=0
    dp[2][0]=1
if r[0]==0:
    #dp[0][0]=0
    #dp[0][1]=0
    dp[2][0]=1
for i in range(1,n):
    if r[i] in (3,1):
        dp[0][i]=min(dp[1][i-1],dp[2][i-1])
    if r[i] in (2,3):
        dp[1][i]=min(dp[0][i-1],dp[2][i-1])
    dp[2][i]=min(dp[0][i-1],dp[2][i-1],dp[1][i-1])+1
print(min(dp[0][n-1],dp[2][n-1],dp[1][n-1]))
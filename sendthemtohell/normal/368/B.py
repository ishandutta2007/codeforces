from sys import *

n,m=(int(z) for z in stdin.readline().split())
arr=[int(z) for z in stdin.readline().split()]
dp=[0]*n
dis=set()
for i in range(n-1,-1,-1):
    dis.add(arr[i])
    dp[i]=len(dis)
for i in range(m):
    k=int(stdin.readline())
    stdout.write(str(dp[k-1])+"\n")
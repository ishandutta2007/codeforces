n,m,k=[int(i) for i in input().split()]
m-=1
a=[int(i) for i in input().split()]
ans=1000000
for i in range(n):
    if a[i]!=0 and a[i]<=k:
        ans=min(ans,abs(i-m))
print(ans*10)
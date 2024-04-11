l1,r1,l2,r2,k=(int(z) for z in input().split())
L=max(l1,l2)
R=min(r1,r2)
ans=0
if L<=k<=R:
    ans-=1
print(max(ans+R-L+1,0))
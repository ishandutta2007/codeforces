n,a=(int(z) for z in input().split())
cr=[int(z) for z in input().split()]
cr2=cr[max(0,2*a-n-1):min(n,2*a-1)]
cr1=cr[:max(0,2*a-n-1)]+cr[min(n,2*a-1):]
ans=0
for i in range(len(cr2)):
    if cr2[i]==cr2[-i-1]==1:
        ans+=1
print(ans+sum(cr1))
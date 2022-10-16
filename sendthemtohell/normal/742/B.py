old=[0]*100001
new=[0]*100001
n,x=(int(z) for z in input().split())
s=[int(z) for z in input().split()]
for i in s:
    old[i]+=1
    if i^x<100001:
        new[i^x]+=1
ans=0
for i in range(100001):
    ans+=old[i]*new[i]
    if x==0:
        ans-=old[i]
ans//=2
print(ans)
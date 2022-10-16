n,b,d=(int(z) for z in input().split())
r=[int(z) for z in input().split()]
i=0
ans=0
cur=0
for i in range(n):
    if r[i]<=b:
        cur+=r[i]
        if cur>d:
            cur=0
            ans+=1
print(ans)
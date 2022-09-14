n=int(input())
s=input()
c=set()
ans=0
ma=['LD','LU','RD','RU']
may=[set(i) for i in ma]
for i in s:
    if not i in c:
        c.add(i)
        if len(c)>1 and not c in may:
            ans+=1
            c=set(i)
if c:
    ans+=1
print(ans)
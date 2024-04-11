r=dict()
c=dict()
ans=[]
n,m=(int(z) for z in input().split())
ans.append(n*n)
for i in range(m):
    x,y=(int(z) for z in input().split())
    #assert (x not in r) or (y not in c)
    if x in r and y in c:
        pl=0
        r[x]+=1
        c[y]+=1
    elif x in r:
        pl=n-len(r)
        r[x]+=1
        c[y]=1
    elif y in c:
        pl=n-len(c)
        c[y]+=1
        r[x]=1
    else:
        pl=2*n-1-len(c)-len (r)
        c[y]=1
        r[x]=1
    ans.append(ans[-1]-pl)
print(" ".join(map(str,ans[1:])))
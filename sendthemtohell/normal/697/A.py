t,s,x=(int(z) for z in input().split())
x-=t
if x>=0 and x%s in [0,1] and x!=1:
    print("YES")
else:
    print("NO")
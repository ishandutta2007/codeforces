n,m=map(int,input().split())

x=10000000
y=0    
if m!=0:
    for i in range(m):
        
        a,b=map(int,input().split())
        c=min(a,b)
        d=max(a,b)
        #print(d)
        if c>y:
            y=c
        if d<x:
            x=d
    if x-y<0:
        print(0)
    else:
        print(x-y)
else:
    print(n-1)
n=int(raw_input())
a={}
b=[]
for i in xrange(n):
    x,p=raw_input().split();
    p=int(p)
    if x in a.keys():
        a[x]+=p;
    else:
        a[x]=p;
    b.append((x,a[x]));
mx=max(a.values());
for x,p in b:
    if p>=mx and a[x]==mx:
        print x
        break
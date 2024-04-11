s,x1,x2=[int(i) for i in input().split()]
t1,t2=[int(i) for i in input().split()]
p,d=[int(i) for i in input().split()]
ans=abs(x1-x2)*t2
if d==-1:
    x1,x2=s-x1,s-x2
    p=s-p
x1t=[(x1-p)*t1,(2*s-x1-p)*t1,(2*s+x1-p)*t1]
x2t=[(x2-p)*t1,(2*s-x2-p)*t1,(2*s+x2-p)*t1]
while x1t[0]<0:
    x1t.pop(0)
while x2t[0]<x1t[0]:
    x2t.pop(0)
ans=min(ans,x2t[0])
print(ans)
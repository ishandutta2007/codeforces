s,x1,x2=(int(z) for z in input().split())
t1,t2=(int(z) for z in input().split())
p,d=(int(z) for z in input().split())

absol=max(x1-x2,x2-x1)
ttoarr=0
if p>x1 and d>0:
    ttoarr=(2*s-p-x1)*t1
    d=-1
elif p<x1 and d<0:
    ttoarr=(p+x1)*t1
    d=1
else:
    ute=max(p-x1,x1-p)
    ttoarr=ute*t1
p=x1    
ttocome=0
if p>x2 and d>0:
    ttocome=(2*s-p-x2)*t1
elif p<x2 and d<0:
    ttocome=(p+x2)*t1
else:
    ute=max(p-x2,x2-p)
    ttocome=ute*t1

print(min( absol*t2 , ttoarr + ttocome ))
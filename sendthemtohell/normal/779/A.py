n=int(input())
a=[int(z) for z in input().split()]
b=[int(z) for z in input().split()]
c1,d1,e1,f1,g1=0,0,0,0,0
c2,d2,e2,f2,g2=0,0,0,0,0
for i in a:
    if i==1:
        c1+=1
    elif i==2:
        d1+=1
    elif i==3:
        e1+=1
    elif i==4:
        f1+=1
    else:
        g1+=1
for i in b:
    if i==1:
        c2+=1
    elif i==2:
        d2+=1
    elif i==3:
        e2+=1
    elif i==4:
        f2+=1
    else:
        g2+=1
if (c1+c2)&1 or (d1+d2)&1 or (e1+e2)&1 or (f1+f2)&1 or (g1+g2)&1:
    print(-1)
else:
    print((abs((c1+c2)//2-c1)+abs((d1+d2)//2-d1)+abs((e1+e2)//2-e1)+abs((f1+f2)//2-f1)+abs((g1+g2)//2-g1))//2)
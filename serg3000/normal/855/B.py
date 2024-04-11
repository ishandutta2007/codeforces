n,p,q,r=map(int,input().split())
a=list(map(int,input().split()))
z=-(100000000000000000000000000000)**1000
if q >=0 and p >=0 and r>=0:
    c=-100000000000
    for i in range(len(a)):
        if a[i]>c:
            c=a[i]
    print(c*(q+p+r))
else:
    if q <=0 and p <=0 and r<=0:
        c=100000000000
        for i in range(len(a)):
            if a[i]<c:
                c=a[i]
        print(c*(q+p+r))
    else:
        b2=a[0]*p
        b=[b2]*n
        for i in range(1,len(a)):
            if a[i]*p>b[i-1]:
                b[i]=a[i]*p
            else:
                b[i]=b[i-1]
        t2=a[n-1]*r
        t=[t2]*n
        for i in range(n-2,-1,-1):
            if a[i]*r>t[i+1]:
                t[i]=a[i]*r
            else:
                t[i]=t[i+1]
        for i in range(n):
            if a[i]*q+b[i]+t[i]>z:
                
                z=a[i]*q+b[i]+t[i]
        print(z)
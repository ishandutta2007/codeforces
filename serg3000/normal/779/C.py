n,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[0]*n
for i in range(n):
    c[i]=a[i] - b[i]
c.sort()
z = 0
for i in range(k):
    z+=c[i]
x=0
for i in range(n):
    x+=b[i]
if k!=n:
    if c[k]>0 :
        print(x + z)
    else:
        z=0
        i=0
        while i<n and c[i]<0 :
            z+=c[i]
            i+=1
        
        print(x+z)
else:
    print(x+z)
n,f=map(int,input().split())
a=[0]*n
b=[0]*n
z=[0]*n
for i in range (n):
    a1,b1=map(int,input().split())
    a[i]=a1
    b[i]=b1
for i in range(n):
    z1=min(2*a[i],b[i])-min(a[i],b[i])
    z[i]=z1
z.sort()
c=0
for i in range(n):
    c+=min(a[i],b[i])
for i in range(n-1,n-f-1,-1):
    c+=z[i]
print(c)
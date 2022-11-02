n,k=map(int,input().split())
a=list(map(int,input().split()))
z=0
c=0
b=0
x=0
t=a[0]
m=0
while b+k < n:
    if b==0:
        b==1
    if m==1:
        u=k
    else:
        u=k+1
    for i in range(b,b+u):
        z=0
        if t < a[i]:
            t=a[i]
            b=i
            z=1
            m=1
            break
    if z==0:
        x=1
        print(t)
        break
for i in range(b,n):
    t=max(t,a[i])
if x==0:
    print(t)
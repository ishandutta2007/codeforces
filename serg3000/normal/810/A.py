n,k=map(int,input().split())
a=list(map(int,input().split()))
c=0
for i in range(n):
    z=k-a[i]
    c+=2*z-1
if c<0:
    print(0)
else:
    print(c)
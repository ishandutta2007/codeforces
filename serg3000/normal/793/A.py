n,k=map(int,input().split())

c=0
a=list(map(int,input().split()))
for i in range(1,n):
            if a[i] % k!=a[i -1] % k:
                        c+=1
if c!=0:
    print(-1)
else:
    b=min(a)
    for i in range(0,n):
        c+=a[i]-b
    print(c // k)
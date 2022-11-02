n,m,k=map(int,input().split())
a=list(map(int,input().split()))
b=n
for i in range(n):
    if a[i]!=0 and a[i]<=k:
        c=abs(m - (i+1))
        if c<b:
            b = c
print(b * 10)
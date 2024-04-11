n=int(input())
a=list(map(int,input().split()))
a.sort()
c=0
for i in range(n):
    c+=a[n-1]-a[i]
print(c)
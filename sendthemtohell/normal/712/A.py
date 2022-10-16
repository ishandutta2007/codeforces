n=int(input())
a=[int(z) for z in input().split()]

b=[0]*n
s=0
for i in range(n-1,-1,-1):
    a[i]+=s
    b[i]=a[i]
    s-=b[i]
    s*=-1
print( ' '.join(map(str, b)) )
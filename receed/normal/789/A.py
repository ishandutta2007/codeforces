n,k=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
x=0
for i in range(n):
    x+=(a[i]+k-1)//k
print((x+1)//2)
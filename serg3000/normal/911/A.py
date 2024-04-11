n=int(input())
a=list(map(int,input().split()))
m=100000000000000000000000000000
for i in range(n):
    if a[i] < m:
        m = a[i]
l=-100000000000000000000000
z=1000000000000000000000000000000
for i in range(n):
    if a[i] == m:
        z=min(z, i - l)
        l=i
print(z)
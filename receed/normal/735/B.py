n,n1,n2=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
a.sort()
if n1>n2:
    n1,n2=n2,n1
s1=s2=0
for i in range(n-n1,n):
    s2+=a[i]
for i in range(n-n1-n2,n-n1):
    s1+=a[i]
print(s1/n2+s2/n1)
n=int(input())
a=[int(z) for z in input().split()]
b=[int(z) for z in input().split()]
s1,s2=0,0
for i in range(n):
    s1|=a[i]
    s2|=b[i]
print(s1+s2)
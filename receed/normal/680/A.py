a=[int(i) for i in input().split()]
s=sum(a)
mi=s
for i in a:
    n=a.count(i)
    if n>2:
        mi=min(mi,s-3*i)
    elif n==2:
        mi=min(mi,s-2*i)
print(mi)
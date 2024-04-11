n,m=map(int,raw_input().split())
a=map(int,raw_input().split())
s=0
for i in xrange(n):
    for j in xrange(i):
        if abs(a[j]-a[i])<=m:
            s+=1
print s*2
n,m,k=map(int,raw_input().split())
a=[10000000]*m
for i in xrange(n):
    x,y=map(int,raw_input().split())
    x-=1
    a[x]=min(a[x],y)
print min(sum(a),k)
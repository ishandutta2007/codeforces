x={}
d={}
n=input()
for i in range(n):
    x[i],d[i]=map(int,raw_input().split())
f=False
for i in range(n):
    for j in range(n):
        if i!=j and x[i]+d[i]==x[j] and x[j]+d[j]==x[i]:
            f=True
print "YES" if f else "NO"
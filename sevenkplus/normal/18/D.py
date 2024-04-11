a=[-1]*2002
a[0]=0
for i in xrange(int(raw_input())):
    s,t=raw_input().split()
    t=int(t)+1
    if s[0]=='w':
        a[t]=a[0]
    elif a[t]>=0:
        a[0]=max(a[0],a[t]+(1<<t-1))
print a[0]
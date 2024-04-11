f=[0 for x in range(1,1000)];
g=[0 for x in range(1,1000)];
t=1;cnt=0;
n=int(raw_input());
if n==2:
    print -1;
if n!=2:
    for x in xrange (2,1000):
        if f[x]==0:
            i=x+x;
            t*=x;
            g[cnt]=x;cnt+=1;
            if cnt==n:
                break;
            while i<=800:
                f[i]=1;
                i+=x;
    for i in xrange(0,n):
        print t/g[i];
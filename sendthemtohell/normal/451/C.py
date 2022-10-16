from sys import *

t=int(stdin.readline())
mm,mmm,mmmm,m=0,0,0,0
for i in range(t):
    n,k,d1,d2=(int(z) for z in stdin.readline().split())
    m=d1+d2
    mm=2*max(d1,d2)-min(d1,d2)
    mmm=2*d1+d2
    mmmm=2*d2+d1
    if (k-mmm>=0 and (k-mmm)%3==0 and n-mmmm-k>=0 and (n-mmmm-k)%3==0) or (k-mmmm>=0 and (k-mmmm)%3==0 and n-mmm-k>=0 and (n-mmm-k)%3==0) or (k-m>=0 and (k-m)%3==0 and n-mm-k>=0 and (n-mm-k)%3==0) or (k-mm>=0 and (k-mm)%3==0 and n-m-k>=0 and (n-m-k)%3==0):
        stdout.write("yes\n")
    else:
        stdout.write("no\n")
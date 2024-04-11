n,k,p=map(int,raw_input().split())
if k<=(n-1)/2:
    MIN=-1
    MINP=-1
    for i in xrange(1,min(10,k+1)):
        T=k-i+(n-i-(k-i)*2+1)/2
        if T>=MIN:
            MIN=T
            MINP=i
s=""
for i in xrange(p):
    x=input()
    if k==0:
        s+="."
    elif k==n:
        s+="X"
    elif k>(n-1)/2:
        if (x%2==1) and (x<=(n-k)*2):
            s+="."
        else:
            s+="X"
    else:
        if MINP==0:
            if (x%2==n%2) and (x>=n-k*2+2):
                s+="X"
            else:
                s+="."
        else:
            if x>=n-MINP+1:
                s+="X"
            elif (x%2==(n-MINP+1)%2) and (x>=n-MINP-1-(k-MINP)*2+2):
                s+="X"
            else:
                s+="."
print s
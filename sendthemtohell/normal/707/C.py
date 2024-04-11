def de(n):
    d=2
    while 1:
        if(n%d==0):
            return d


n=int(input())

if n<=2:
    print(-1)
else:
    if n%2:
        m=(n-1)//2+1
        n=m-1
        print(2*n*m,m*m+n*n)
    else:
        m=n//2
        n=1
        if m>n:
            print(m*m-n*n,m*m+n*n)
        else:
            print(-m*m+n*n,m*m+n*n)
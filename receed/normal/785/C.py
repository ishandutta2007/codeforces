n,m=[int(i) for i in input().split()]
if m>=n:
    print(n)
else:
    l,r=-1,10**18
    now=n-m
    while r-l>1:
        md=(l+r)//2
        if now+md*m-(m*2+md+1)*md//2<=0:
            r=md
        else:
            l=md
    print(r+m)
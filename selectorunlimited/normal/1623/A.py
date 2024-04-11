t=int(input())
for ii in range (t):
    n,m,r1,c1,r2,c2=map(int,input().split())
    r,c=r1,c1
    n1,m1=n,m
    if r1==r2 and c1==c2:
        print(0)
    else:
        dr,dc=1,1
        count=0
        while r!=r2 and c!=c2:
            #print(r,c,dr,dc)
            if r+dr>n1 or r+dr<1:
                dr=-dr
            if c+dc>m1 or c+dc<1:
                dc=-dc
            r=r+dr
            c=c+dc
            count+=1
        print(count)
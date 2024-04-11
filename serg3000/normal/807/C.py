t=int(input())
for i in range(t):
    x,y,p,q=map(int,input().split())
    if p==1 and q==1 and x//y!=1 or p==0 and x!=0:
        z=-1
    else:
    
        start=0
        stop=10**9
        while start<=stop-2 :
            mid=(start+stop)//2
            #print(mid)
            if mid * q - y + x>=mid * p and mid * q>=y and mid*p>=x:
                stop=mid 
            else:
                start=mid 
        z=stop*q-y
    print(z)
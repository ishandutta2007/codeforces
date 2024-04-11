n,k=(map(int,input().split()))
if n==0:
    print(0)
else:
    a=[]
    while n!=0:
        a.append(n%10)
        n=n//10
    c=0
    z=0
    x=0
    g=0
    q=0
    
    for i in range(len(a)):
        if a[i]==0:
            c+=1
        else:
            z+=1
    i=0
    while g!=k and i<len(a):
        if a[i]==0:
            g+=1
        else:
            x+=1
        i+=1
        
    
    if x==z:
        print(len(a)-1)
    else:
        print(x)
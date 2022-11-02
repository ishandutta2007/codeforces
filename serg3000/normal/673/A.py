n=int(input())
a=list(map(int,input().split()))
if a[0]>15:
    print(15)
else:
    i=0
    c=0
    while c!=1 and i!=n-1:
        if a[i+1]-a[i]>15:
            c=1
        else:
            i+=1
    print(min(a[i]+15,90))
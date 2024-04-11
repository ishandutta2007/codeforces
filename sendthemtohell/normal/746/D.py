n,k,a,b=(int(z) for z in input().split())
x,y="G","B"
if a<b:
    a,b=b,a
    x,y=y,x
ans=''
if (b+1)*k<a:
    print("NO")
else:
    r,curr=0,x
    for i in range(n):
        if a-b<=1 and r<k:
            ssss=0
            for j in range(i,n):
                if ssss%2:
                    ans+=y
                else:
                    ans+=x
                ssss+=1
            break
        if r<k:
            ans+=x
            r+=1
            a-=1
        else:
            ans+=y
            r=0
            b-=1
print(ans)
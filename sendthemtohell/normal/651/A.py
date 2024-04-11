a,b=(int(z) for z in input().split())
res=0
while a*b>1:
    if a>b:
        a,b=b,a
    res+=1
    a+=1
    b-=2
print(res)
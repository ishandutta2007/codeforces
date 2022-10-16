a,b=(int(z) for z in input().split())
if a-b in [0,1,-1] and a+b>0 and a>=0 and b>=0:
    print("YES")
else:
    print("NO")
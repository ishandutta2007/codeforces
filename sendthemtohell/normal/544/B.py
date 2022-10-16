from sys import *

n,k=(int(z) for z in input().split())
if k>((n+1)//2)*((n+1)//2)+(n//2)*(n//2):
    print("NO")
    exit(0)
print("YES")
mat=[]
for i in range(n):
    if not i%2:
        if not n%2:
            g=min(n//2,k)
            res=g*"LS"+(n//2-g)*"SS"
            k-=g
        else:
            g=min(n//2,k)
            res=g*"LS"+(n//2-g)*"SS"
            if g==k:
                res+="S"
            else:
                g+=1
                res+="L"
            k-=g
    else:
        if not n%2:
            g=min(n//2,k)
            res=g*"SL"+(n//2-g)*"SS"
            k-=g
        else:
            g=min(n//2,k)
            res=g*"SL"+(n//2-g)*"SS"
            res+="S"
            k-=g
    mat.append(res)
for i in mat:
    print(i)
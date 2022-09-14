from fractions import gcd
def nok(a,b):
    return a*b//gcd(a,b)

n=int(input())
a=[0]+[int(i) for i in input().split()]
ans=1
for i in range(1,1+n):
    if a[i]!=i:
        now=i
        res=-1
        for j in range(n):
            now=a[now]
            if now==i:
                res=j+1
                if res%2==0:
                    res//=2
                ans=nok(ans,res)
                break
        else:
            ans=-1
            break
print(ans)
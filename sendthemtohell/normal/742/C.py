def gcd(a,b):
    while b:
        a,b=b,a%b
    return a

def lcm(arr):
    if len(arr)==1:
        return arr[0]
    else:
        a=arr.pop()
        b=arr.pop()
        arr.append(a*b//gcd(a,b))
        return lcm(arr)

n=int(input())
lv=[(int(z)-1) for z in input().split()]
tbl=set(lv)
if len(tbl)==n:
    cntlcm=[]
    vv=[0]*n
    i=0
    while i<n:
        if vv[i]:
            i+=1
        else:
            k=i
            cnt=0
            while not vv[k]:
                cnt+=1
                vv[k]=1
                k=lv[k]
            if cnt%2:
                cntlcm.append(cnt)
            else:
                cntlcm.append(cnt//2)
    print(lcm(cntlcm))
else:
    print(-1)
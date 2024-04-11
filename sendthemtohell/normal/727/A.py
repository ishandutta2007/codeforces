def Solve(a,b):
    if a==b:
        return [a]
    if a>b:
        return []
    if b%2==0:
        s=Solve(a,b//2)
        if s:
            return s+[b]
    if b%10==1:
        s=Solve(a,b//10)
        if s:
            return s+[b]
    return []

n,m=(int(z) for z in input().split())
s=Solve(n,m)
if s:
    print ("YES")
    print (len(s))
    print (' '.join(map(str,s)))
else:
    print ("NO")
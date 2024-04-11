def checkrect(a,n1,n2,m1,m2):
    for i in range(n1,n2+1):
        for j in range(m1,m2+1):
            if a[i][j]!="X":
                return False
    return True

def rect(a,n,m):
    n1,m1,n2,m2=-1,-1,-1,-1
    for i in range(n):
        if "X" in a[i]: 
            if n1==-1:
                n1=i
            n2=i
    for i in range(m):
        if "X" in [a[j][i] for j in range(n)]:
            if m1==-1:
                m1=i
            m2=i
    return checkrect(a,n1,n2,m1,m2)

n,m=(int(z) for z in input().split())
a=[]
for i in range(n):
    a.append(input())
ff=rect(a,n,m)
if ff:
    print("YES")
else:
    print("NO")
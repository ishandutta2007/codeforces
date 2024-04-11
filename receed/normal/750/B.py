n=int(input())
x=0
ans='YES'
for i in range(n):

    a,s=input().split()
    a=int(a)
    if s=='South':
        if x+a>20000 or x==20000:
            ans='NO'
        x+=a
    elif s=='North':
        if x==0 or x-a<0:
            ans='NO'
        x-=a
    else:
        if x%20000==0:
            ans='NO'
if x!=0:
    ans='NO'
print(ans)
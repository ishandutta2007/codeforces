n,t,k,d=map(int,input().split())
c=((n+k-1)//k)*t
x=c-d
b1=((x-1)//t*k)
b2=((c-1)//t)*k
if b1+b2>=n:
    print('YES')
else:
    print('NO')
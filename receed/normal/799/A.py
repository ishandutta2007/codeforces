n,t,k,d=[int(i) for i in input().split()]
a = (n+k-1)//k*t
b=1000000000
for i in range(n//k+1):
    b=min(b,max(d+i*t,(n-i*k+k-1)//k*t))
if b<a:
    print('YES')
else:
    print('NO')
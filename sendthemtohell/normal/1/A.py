m,n,a=(int(z) for z in input().split ())
if n%a:
    n=n//a+1
else:
    n//=a
if m%a:
    m=m//a+1
else:
    m//=a
print(n*m)

def f(n,k):
    if k==0:
        return n+1
    if n==1:
        return 1
    return f(n-1,k%(2**(n-1)))

n,k=(int(z) for z in input().split())
print(f(n,k))
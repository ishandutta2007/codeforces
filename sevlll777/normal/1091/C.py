n = int(input())
dels = set()
for k in range(1, int((n+1)**0.5)+1):
    if n%k==0:
        dels.add(k)
        dels.add(n//k)
for d in sorted(dels, reverse=True):
    z = n//d
    print((n*(n+1)//2-z*d*(d-1)//2)//d, end=' ')
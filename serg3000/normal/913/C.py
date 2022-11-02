n,l = map(int,input().split())
a = list(map(int,input().split()))
#print(0)
b = [0] * n
b[0] = a[0]
if n == 1 and l == 1:
    print(a[0])
else:
    for i in range(1,n):
        b[i] = min(a[i],b[i - 1] * 2)
        if b[i] < b[i - 1]:
            for j in range(i):
                b[j] = min(b[i],b[j])
    c=[0] * n
    c[0] = 1
    s = 0
    z = 100000000000000000000
    for i in range(1,n):
        c[i] = c[i - 1] * 2
    while l > c[n - 1]:
        s += b[n - 1] * (l // c[n - 1])
        l = l % c[n - 1]
        
    #print(0)
    while l > 0:
        for i in range(1,n):
            if l <= c[i] and l >= c[i - 1] :
                z = min(z, s + b[i])
                l -= c[i - 1]
                s += b[i - 1]
                
            #print(l)
    #print(b)
    print(min(z,s))
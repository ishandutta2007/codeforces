def bin(n):
    if n == 0:
        return 1
    else:
        if n % 2 == 1:
            return bin(n - 1) * 2
        else:
            b = (bin(n // 2)) % 1000000007
            return b * b;
x, k = map(int,input().split())
if x == 0:
    print(0)
else:
    z = bin(k + 1) % 1000000007
    z = z * (x - 1)
    z = z % 1000000007
    z += bin(k)
    z += 1
    while(z < 0): 
        z += 1000000007
    print(z % 1000000007)
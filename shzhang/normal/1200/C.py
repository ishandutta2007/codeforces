def gcd(a, b):
    return a if b == 0 else gcd(b, a%b)
 
def lcm(a, b):
    return (a * b) // gcd(a, b)
 
l1 = [int(x) for x in input().split()]
n = l1[0]; m = l1[1]; q = l1[2]
 
lcmval = lcm(n, m)
 
for i in range(q):
    sx, sy, ex, ey = [int(x) for x in input().split()]
    sy -= 1; ey -= 1;
    sy *= m if sx == 1 else n
    ey *= m if ex == 1 else n
    if sy // lcmval == ey // lcmval:
        print("YES")
    else:
        print("NO")
from math import sqrt
def gd(n, k):
    ans = 1
    obrans = 1
    for i in range(2, int(sqrt(n) + 1)):
        j = 0
        while n % i == 0:
            j += 1
            n //= i
        ans *= pow(i, j%k)
        obrans *= pow(i, (-j)%k)
    ans *= n
    obrans *= pow(n, (k-1))
    return ans, obrans
n, k = map(int,input().split())
oba = set()
dct = {}
for i in list(map(int,input().split())):
    a,b = gd(i, k)
    dct[a] = dct.get(a, 0) + 1
    a,b = min(a,b), max(a,b)
    oba.add((a,b))
ans = 0
for i, j in oba:
    if i == j:
        ans += (dct.get(i, 0)  * dct.get(j, 0) - dct.get(i, 0)) // 2
    else:
        ans += dct.get(i, 0) * dct.get(j, 0)
print(ans)
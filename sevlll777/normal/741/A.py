from math import gcd
def lcm(a, b): return a * b // gcd(a, b)
n = int(input())
A = [0] + list(map(int, input().split()))
g = {}
for i in range(1, n + 1):
    g[A[i]] = i
if len(g) != n:
    print(-1)
else:
    clc = 1
    for i in g:
        x = g[i]
        cnt = 1
        while x != i:
            x = g[x]
            cnt += 1
        if cnt % 2 == 0:
            cnt //= 2
        clc = lcm(clc, cnt)
    print(clc)
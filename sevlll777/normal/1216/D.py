from math import gcd
n = int(input())
A = list(map(int, input().split()))
m = max(A)
g = 0
for i in A:
    g = gcd(g, m - i)
ans = 0
for i in A:
    ans += (m - i) // g
print(ans, g)
from math import gcd
ans = []
for _ in range(int(input())):
    p, q, b = map(int, input().split())
    q //= gcd(p, q)
    if pow(b, 100, q) == 0:
        ans.append('Finite')
    else:
        ans.append('Infinite')
print('\n'.join(ans))
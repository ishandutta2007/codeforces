from math import *

n = int(raw_input())

ans = 0
for i in xrange(5, 8):
    if i <= n:
        ans += factorial(n) / factorial(n - i) / factorial(i)

print ans
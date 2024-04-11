from math import *

mem = {}

def solve(n, a, b):
    if n == 0:
        return a == 0 and b == 0

    if (n, a, b) in mem:
        return mem[(n, a, b)]
    res = 0
    for i in xrange(a + 1):
        for j in xrange(b + 1):
           res += solve(n - 1, a - i, b - j)
    mem[(n, a, b)] = res
    return res

n = int(raw_input())

print solve(n, 3, 5)
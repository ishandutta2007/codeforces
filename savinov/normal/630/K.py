from math import *
from fractions import gcd
from itertools import combinations
n = int(raw_input())

ans = 0

arr = [i + 2 for i in xrange(9)]

for r in xrange(0, len(arr) + 1):
    for mask in combinations(arr, r):
        l = 1
        for i in mask:
            l = l / gcd(i, l) * i
        ans += n / l if r % 2 == 0 else -(n / l)

print ans
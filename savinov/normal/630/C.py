from math import *

n = int(raw_input())

ans = 0

for i in xrange(1, n + 1):
    ans += 2 ** i

print ans
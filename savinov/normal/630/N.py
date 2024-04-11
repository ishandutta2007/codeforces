from math import *
from fractions import gcd
# n = int(raw_input())

a, b, c = map(int, raw_input().split())

if a < 0:
    a, b, c = -a, -b, -c

d = b * b - 4 * a * c

assert d > 0

d = sqrt(d)

print "%.10f" % ((-b + d) / 2 / a)
print "%.10f" % ((-b - d) / 2 / a)
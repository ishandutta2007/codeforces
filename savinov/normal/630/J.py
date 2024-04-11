from math import *
from fractions import gcd
n = int(raw_input())

l = 1

for i in xrange(2, 11):
    l = l * i / gcd(i, l)

print n / l
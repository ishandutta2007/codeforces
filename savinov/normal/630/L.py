from math import *
from fractions import gcd
# n = int(raw_input())

s = raw_input()

s = s[0] + s[2] + s[4] + s[3] + s[1]

s = int(s)

s = s ** 5

s %= 10 ** 5

print "%05d" % s
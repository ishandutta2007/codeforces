from fractions import gcd
from math import floor
a, b = map(float, raw_input().split())
ans = 1E10
for c in (a - b, a + b):
  num = floor(c / (2 * b))
  if num > 0:
    x = c / (2 * num)
    ans = min(ans, x)

if ans == 1E10:
  ans = -1
print ans
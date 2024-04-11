from math import gcd, ceil, log, log2
from collections import deque
from bisect import bisect_right, bisect_left
for _ in range(int(input())):
    a, b, n = map(int, input().split())
    if n % 3 == 0:
        print(a)
    elif n % 3 == 1:
        print(b)
    else:
        print(a ^ b)
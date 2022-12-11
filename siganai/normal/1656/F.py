#!/usr/bin/env PyPy3

from collections import Counter, defaultdict, deque
import itertools
import re
import math
from functools import reduce
import operator
import bisect
import heapq
import functools
mod=10**9+7

import sys
input=sys.stdin.readline
def f(x):
    res = 0
    mi = a[0] + x
    ma = a[-1] + x
    for i in range(1,n-1):
        if a[i] + x > 0:
            res += mi * (a[i] + x)
        else:
            res += ma * (a[i] + x)
    res += ma * mi
    return res - (n-1) * (x ** 2)
INF = 10 ** 9
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    #mina = min(a)
    #maxa = max(a)
    mi = a[0] * (n-2) + sum(a)
    ma = a[-1] * (n-2) + sum(a)
    if mi > 0 or ma < 0:
        print('INF')
    else:
        high = INF
        low = -INF
        while high - low > 1:
            mid = (high + low) // 2
            #print(f(mid_l),f(mid_r))
            if f(mid) >= f(mid+1):
                high = mid
            else:
                low = mid
        print(f(high))
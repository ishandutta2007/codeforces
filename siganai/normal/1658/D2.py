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
 
def solve(l: int, r: int, s: set):
    if l % 2 == 0 and r % 2 == 1:
        t = set()
        for v in s: t.add(v >> 1)
        return solve(l >> 1, r >> 1, t) << 1
    else:
        for v in s:
            if (v ^ 1) not in s:
                ok = True
                ans = v
                if l % 2 == 0: ans ^= r
                else: ans ^= l
                for x in s:
                    if (x ^ ans) < l or (x ^ ans) > r:
                        ok = False
                        break
                if ok: return ans
            
 
t = int(input())
for _ in range (t):
    l, r = map(int, input().split())
    s = set(map(int, input().split()))
    print(solve(l, r, s))
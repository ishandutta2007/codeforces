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

t = int(input())
for _ in range(t):
    n,r,b=map(int,input().split())
    row = -(-r//(b+1))
    ans = []
    c = row
    c1 = r % (b+1)
    for _ in range(row):
        ans.append('R')
    if r % (b+1) == 0:
        for _ in range(b):
            ans.append('B')
            for _ in range(row):
                ans.append('R')
    else:
        for i in range(b):
            ans.append('B')
            if i < c1 - 1:
                for _ in range(row):
                    ans.append('R')
            else:
                for _ in range(row-1):
                    ans.append('R')
    print(''.join(ans))
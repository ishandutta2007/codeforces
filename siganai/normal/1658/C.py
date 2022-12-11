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

t=int(input())
for _ in range(t):
    n=int(input())
    c = list(map(int,input().split()))
    if n == 1 and c[0] == 1:
        print('YES')
        continue
    flg = 1
    cnt1 = 0
    for i in range(n):
        if c[i] == 1:
            cnt1 += 1
        if c[i-1] + 1 < c[i]:
            #print(c[i-1],c[i])
            flg = 0
            break
    if cnt1 != 1:
        print('NO')
        continue
    if flg:
        print('YES')
    else:
        print('NO')
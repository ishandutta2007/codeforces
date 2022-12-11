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
    l,r = map(int,input().split())
    a = list(map(int,input().split()))
    moto = [0] * 18
    for i in range(r+1):
        for j in range(18):
            if i >> j & 1:
                moto[j] += 1
    ima = [0] * 18
    for aa in a:
        for j in range(18):
            if aa >> j & 1:
                ima[j] += 1
    ans = 0
    for i in range(18):
        if moto[i] != ima[i]:
            ans += 1 << i
    print(ans)
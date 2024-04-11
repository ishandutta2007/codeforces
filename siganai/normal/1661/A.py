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
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    for i in range(n):
        if a[i] < b[i]:
            a[i],b[i] = b[i],a[i]
    ans = 0
    for i in range(n-1):
        ans += abs(a[i+1] - a[i])
        ans += abs(b[i+1] - b[i])
    print(ans)
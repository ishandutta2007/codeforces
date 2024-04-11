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
    n,b,x,y = map(int,input().split())
    ans = 0
    now = 0
    for i in range(n):
        if now + x <= b:
            now += x
            ans += now
        else:
            now -= y
            ans += now
    print(ans)
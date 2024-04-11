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
    s = list(map(int,input().rstrip()))
    #print(s)
    ans = 0
    for i in range(n-1):
        if s[i] == 0 and s[i+1] == 0:
            ans += 2
    #print(ans)
    for i in range(n-2):
        if s[i] == 0 and s[i+1] == 1 and s[i+2] == 0:
            ans += 1
    print(ans)
#!/usr/bin/env PyPy3

from collections import Counter, defaultdict, deque
import itertools
import re
import math
from functools import reduce
import operator
import bisect
from heapq import *
import functools
mod=998244353

import sys
input=sys.stdin.readline
t = int(input())
INF = 1 << 31
for _ in range(t):
    n,m=map(int,input().split())
    sl = [input().rstrip() for _ in range(n)]
    ans = INF
    for i in range(n):
        for j in range(i+1,n):
            tmp = 0
            for k in range(m):
                tmp += abs(ord(sl[i][k]) - ord(sl[j][k]))
            ans = min(ans,tmp)
    print(ans)
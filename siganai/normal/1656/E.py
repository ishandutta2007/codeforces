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
    n = int(input())
    g = [[] for _ in range(n)]
    for _ in range(n-1):
        a,b=map(int,input().split())
        a,b=a-1,b-1
        g[a].append(b)
        g[b].append(a)
    ans = [0] * n
    ans[0] = len(g[0])
    go = deque([0])
    while go:
        now = go.pop()
        for nex in g[now]:
            if ans[nex]:
                continue
            if ans[now] > 0:
                ans[nex] = -len(g[nex])
            else:
                ans[nex] = len(g[nex])
            go.appendleft(nex)
    print(*ans)
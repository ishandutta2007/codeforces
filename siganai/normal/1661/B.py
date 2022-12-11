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
INF = 10 ** 9
n=int(input())
a=list(map(int,input().split()))
ans = [INF] * 32769
ans[32768] = 0
ans[0] = 0
go = deque([32768,0])
while go:
    now = go.pop()
    if now % 2 == 0:
        if ans[now // 2] == INF:
            ans[now // 2] = ans[now] + 1
            go.appendleft(now//2)
        if ans[(now + 32768) // 2] == INF:
            ans[(now + 32768) // 2] = ans[now] + 1
            go.appendleft((now + 32768) // 2)
    if 0 < now <= 32768:
        if ans[now-1] == INF:
            go.appendleft(now-1)
            ans[now-1] = ans[now] + 1
b = []
for aa in a:
    b.append(ans[aa])
print(*b)
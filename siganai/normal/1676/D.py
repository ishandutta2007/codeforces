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
dx = [1,-1,1,-1]
dy = [1,1,-1,-1]
for _ in range(t):
    n,m=map(int,input().split())
    area = [list(map(int,input().split())) for _ in range(n)]
    ans = 0
    for i in range(n):
        for j in range(m):
            tmp = area[i][j]
            for dir in range(4):
                for k in range(1,max(n,m) + 1):
                    nx,ny = i + dx[dir] * k, j + dy[dir] * k
                    if 0 <= nx < n and 0 <= ny < m:
                        tmp += area[nx][ny]
                    else:
                        break
            ans = max(ans,tmp)
    print(ans)
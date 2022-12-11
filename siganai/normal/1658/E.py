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

import io, os, sys
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n,k=map(int,input().split())
area = [list(map(int,input().split())) for _ in range(n)]
xl = [0] * (n ** 2)
yl = [0] * (n ** 2)

for i in range(n):
    for j in range(n):
        xl[area[i][j] - 1] = i
        yl[area[i][j] - 1] = j
#print(xy)
maxx = 2 * n
maxy = n
minx = 0
miny = -n
ans = [['G'] * n for _ in range(n)]
for i in range(n**2-1,-1,-1):
    x = xl[i];y = yl[i]
    #print(x,y)
    if minx <= x + y <= maxx and miny <= x - y <= maxy:
        ans[x][y] = 'M'
        minx = max(minx,x+y-k)
        maxx = min(maxx,x+y+k)
        miny = max(miny,x-y-k)
        maxy = min(maxy,x-y+k)
        #print(minx,maxx,miny,maxy)
for row in ans:
    print("".join(row))
#print(ans)
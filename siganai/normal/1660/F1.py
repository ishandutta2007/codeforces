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
    n =int(input())
    s=input().rstrip()
    l = [[0,0,0]]
    pl = 0
    mi = 0
    ren = 0
    flg = 0
    for i in range(n):
        if s[i] == '+':
            pl += 1
            flg = 0
        else:
            mi += 1
            if flg:
                ren += 1
                flg = 0
            else:
                flg = 1
        l.append([pl,mi,ren])
    ans = 0
    for i in range(n+1):
        for j in range(i+1,n+1):
            pl = l[j][0] - l[i][0]
            mi = l[j][1] - l[i][1]
            cn = l[j][2] - l[i][2]
            #print(pl,mi,cn)
            if mi - pl >= 0 and (mi - pl) % 3 == 0:
                if (mi - pl) // 3 <= cn:
                    ans += 1
    print(ans)
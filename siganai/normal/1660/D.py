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
    n=int(input())
    a=list(map(int,input().split()))
    zl = []
    ans = 0
    al = 0
    ar = n
    for i in range(n):
        if a[i] == 0:
            zl.append(i)
    if a[-1] != 0:
        zl.append(n)
    st = 0
    for i in range(len(zl)):
        tcnt = 0
        mi = 0
        zflg = 0
        l = []
        for j in range(st,zl[i]):
            if zflg:
                l.append([0,0])
                continue
            if a[j] == 0:
                zflg = 1
                l.append([0,0])
            else:
                if a[j] < 0:
                    mi += 1
                if a[j] == 2 or a[j] == -2:
                    tcnt += 1
                if mi % 2:
                    l.append([-1,tcnt])
                else:
                    l.append([1,tcnt])
        r = []
        tcnt = 0
        mi = 0
        zflg = 0
        for j in range(st,zl[i])[::-1]:
            if zflg:
                r.append([0,0])
                continue
            if a[j] == 0:
                zflg = 1
                r.append([0,0])
            else:
                if a[j] < 0:
                    mi += 1
                if a[j] == 2 or a[j] == -2:
                    tcnt += 1
                if mi % 2:
                    r.append([-1,tcnt])
                else:
                    r.append([1,tcnt])
        for k in range(len(l))[::-1]:
            mi,two = l[k]
            if mi == 1:
                if ans < two:
                    ans = two
                    al = st
                    ar = n - (st + k) - 1
                    break
        for k in range(len(r))[::-1]:
            mi,two = r[k]
            if mi == 1:
                if ans < two:
                    ans = two
                    al = zl[i] - k - 1
                    ar = n - (zl[i])
                    break
        st = zl[i] + 1
    print(al,ar)
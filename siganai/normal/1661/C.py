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
    ma = max(a)
    c1 = 0
    c2 = 0
    upp = 0
    for aa in a:
        #print(ma-aa)
        c1 += (ma - aa) // 3
        c2 += (ma - aa) // 3
        if (ma - aa) % 3 == 1:
            c1 += 1
            upp += ((ma - aa) // 3 + 1) // 2
        elif (ma - aa) % 3 == 2:
            upp += ((ma - aa) // 3) // 2
            c2 += 1
    if c1 == c2:
        print(c2 * 2)
        continue
    if c1 == c2 + 1:
        print(c2 * 2 + 1)
        continue
    #print(c1,c2,upp)
    if c1 > c2:
        dis = (c1 - c2 + 1) // 3
        if dis <= upp:
            c1 -= dis * 2
            c2 += dis 
        else:
            c1 -= upp * 2
            c2 += upp
        ans = max(c1*2-1,c2*2)
    else:
        dis = (c2 - c1 + 1) // 3
        c1 += dis * 2
        c2 -= dis
        ans = max(c1*2-1,c2*2)
    ma += 1
    c1 = 0
    c2 = 0
    upp = 0
    for aa in a:
        #print(ma-aa)
        c1 += (ma - aa) // 3
        c2 += (ma - aa) // 3
        if (ma - aa) % 3 == 1:
            c1 += 1
            upp += ((ma - aa) // 3 + 1) // 2
        elif (ma - aa) % 3 == 2:
            upp += ((ma - aa) // 3) // 2
            c2 += 1
    if c1 == c2:
        print(min(ans,c2 * 2))
        continue
    if c1 == c2 + 1:
        print(min(c2 * 2 + 1,ans))
        continue
    #print(c1,c2,upp)
    if c1 > c2:
        dis = (c1 - c2 + 1) // 3
        if dis <= upp:
            c1 -= dis * 2
            c2 += dis 
        else:
            c1 -= upp * 2
            c2 += upp
        ans = min(ans,max(c1*2-1,c2*2))
    else:
        dis = (c2 - c1 + 1) // 3
        c1 += dis * 2
        c2 -= dis
        ans = min(ans,max(c1*2-1,c2*2))
    print(ans)
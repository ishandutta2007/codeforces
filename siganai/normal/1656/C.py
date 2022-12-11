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
    n = int(input())
    a = list(map(int,input().split()))
    flg1 = 0
    flg0 = 0
    for i in range(n):
        if a[i] == 1:
            flg1 = 1
        if a[i] == 0:
            flg0 = 1
    if flg1 and flg0:
        print('NO')
    elif flg1:
        s = set()
        for i in range(n):
            s.add(a[i])
            if a[i] - 1 in s or a[i] + 1 in s:
                print('NO')
                break
        else:
            print('YES')
    else:
        print('YES')
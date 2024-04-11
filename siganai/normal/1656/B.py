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
    n,k=map(int,input().split())
    a=set(map(int,input().split()))
    flg = 0
    for aa in a:
        if aa + k in a:
            flg = 1
            break
    if flg:
        print('YES')
    else:
        print('NO')
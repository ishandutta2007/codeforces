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
    if n == 1:
        if a[0] == 1:
            print('Yes')
        else:
            print('No')
        continue
    a.sort()
    if a[-1] <= a[-2] + 1:
        print('Yes')
    else:
        print('No')
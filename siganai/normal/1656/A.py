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
    maxa = max(a)
    mina = min(a)
    for i in range(n):
        if maxa == a[i]:
            ans1 = i+1
        if mina == a[i]:
            ans2 = i+1
    print(ans1,ans2)
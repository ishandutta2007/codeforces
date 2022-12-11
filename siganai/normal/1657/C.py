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
    n = int(input())
    st = input().rstrip()
    cnt = 0
    use = 0
    now = 0
    while now < n - 1:
        if st[now] == ')' and st[now+1] == '(':
            now += 2
            while now < n:
                if st[now] == '(':
                    now += 1
                else:
                    now += 1
                    cnt += 1
                    use = now
                    break
        else:
            now += 2
            cnt += 1
            use = now
    print(cnt,n-use)
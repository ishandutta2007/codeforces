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
mod=998244353

import sys
input=sys.stdin.readline

t = int(input())
for _ in range(t):
    n=int(input())
    if n % 2:
        print(0)
    else:
        ans = 1
        for i in range(1,n//2+1):
            ans *= i
            ans %= mod
        ans **= 2
        ans %= mod
        print(ans)
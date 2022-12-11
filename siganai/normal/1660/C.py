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

a = ord('a')
t=int(input())
for _ in range(t):
    s = input().rstrip()
    l = [0] * 26
    ans = len(s)
    for i in range(len(s)):
        now = ord(s[i]) - a
        l[now] += 1
        if l[now] % 2 == 0:
            ans -= 2
            l = [0] * 26
    print(ans)
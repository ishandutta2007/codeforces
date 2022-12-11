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
    a,b=map(int,input().split())
    if a == 0:
        print(1)
    else:
        print(2*b+a+1)
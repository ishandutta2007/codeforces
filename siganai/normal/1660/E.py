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

#import io, os
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
import sys
input=sys.stdin.readline
t = int(input())
for _ in range(t):
    _=input()
    n = int(input())
    area = [list(map(int,input().rstrip())) for _ in range(n)]
    cnt = 0
    #gy = set([i for i in range(n)])
    for i in range(n):
        for j in range(n):
            if area[i][j]:
                cnt += 1
    ma = 0
    for i in range(n):
        tmp = 0
        for j in range(n):
            if area[j][(i+j) % n]:
                tmp += 1 
        ma = max(ma,tmp)
    #print(ma)
    print(cnt - n + 2 * (n - ma))
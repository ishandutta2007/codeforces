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
INF = 1 << 30
area = [[INF] * 51 for _ in range(51)]
area[0][0] = 0
able_move = set()
for i in range(51):
    for j in range(51):
        if i == j == 0:
            continue
        a = i ** 2 + j ** 2
        if int(a ** (1 / 2)) ** 2 == a:
            able_move.add((i,j))
            able_move.add((-i,-j))
            able_move.add((-i,j))
            able_move.add((i,-j))
go = deque([[0,0]])
while go:
    nowx,nowy = go.pop()
    for i,j in able_move:
        if 0 <= nowx + i <= 50 and 0 <= nowy + j <= 50:
            if area[nowx+i][nowy+j] == INF:
                area[nowx+i][nowy+j] = area[nowx][nowy] + 1
                go.appendleft([nowx+i,nowy+j])
t = int(input())
for _ in range(t):
    x,y = map(int,input().split())
    print(area[x][y])
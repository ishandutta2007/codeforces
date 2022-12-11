import bisect
import functools
import heapq
import itertools
import math
import operator
import re
import sys
import typing
from collections import Counter, defaultdict, deque
from functools import reduce
import sys
input=sys.stdin.readline
'''
INF = 1 << 31
r,g,b=map(int,input().split())
dp = [[INF] * 901 for _ in range(1000)]
for i in range(900):
    dp[i][0] = 0
for i in range(1000):
    pos = i - 500
    for j in range(1,r+g+b+1):
        if j <= r:
            dp[i][j] = min(dp[i][j],dp[i-1][j-1]+abs(pos+100))
        elif j <= r + g:
            dp[i][j] = min(dp[i][j],dp[i-1])
'''
t = int(input())
for _ in range(t):
    n = int(input())
    dif = [0] * 10
    for i in range(n):
        b,d=map(int,input().split())
        dif[d-1] = max(dif[d-1],b)
    for i in range(10):
        if dif[i] == 0:
            print('MOREPROBLEMS')
            break
    else:
        print(sum(dif))
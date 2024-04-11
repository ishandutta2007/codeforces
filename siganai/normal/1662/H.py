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

def divisor(n):
    sq = n**0.5
    border = int(sq)
    table = []
    bigs = []
    for small in range(1, border+1):
        if n%small == 0:
            table.append(small)
            big = n//small
            bigs.append(big)
    if border == sq:#n
        bigs.pop()
    table += reversed(bigs)
    return table
t = int(input())
for _ in range(t):
    w,l=map(int,input().split())
    s = set()
    s.add(2)
    g1 = math.gcd(w-1,l-1)
    t = divisor(g1)
    for tt in t:
        s.add(tt)
    g2 = math.gcd(w,l-2)
    t = divisor(g2)
    for tt in t:
        s.add(tt)
    g3 = math.gcd(w-2,l)
    t = divisor(g3)
    for tt in t:
        s.add(tt)
    print(len(s),*sorted(list(s)),sep=' ')
#!/usr/bin/env PyPy3

from collections import Counter, defaultdict, deque
import itertools
import re
import math
from functools import reduce
import operator
import bisect
from heapq import *
import functools
mod=998244353

import sys
input=sys.stdin.readline

n = int(input())
if n == 2:
    print(4)
    exit()
INF = 1 << 31
xy = [list(map(int,input().split())) for _ in range(n)]
dist = [[INF] * n for _ in range(n)]
for i in range(n):
    for j in range(i+1,n):
        dist[i][j] = dist[j][i] = abs(xy[i][0] - xy[j][0]) + abs(xy[i][1] - xy[j][1])
ml = []
for i in range(n):
    ml.append(min(dist[i]))
same_ok = [[0] * n for _ in range(n)]
for i in range(n):
    for j in range(i+1,n):
        if dist[i][j] == ml[i] == ml[j]:
            same_ok[i][j] = same_ok[j][i] = 1
li = []
used = [0] * n
for i in range(n):
    if used[i]:
        continue
    tmp = [i]
    s = set([i])
    for j in range(n):
        if ml[i] == ml[j] == dist[i][j]:
            tmp.append(j)
            s.add(j)
    flg = 1
    #print(tmp)
    for j in tmp:
        for k in range(n):
            if j == k:continue
            if dist[k][j] == ml[j]:
                if not k in s:
                    flg = 0
                    break
            else:
                if k in s:
                    flg = 0
                    break
        if not flg:
            break
    if flg:
        li.append(len(tmp))
        #print(tmp)
        for j in tmp:
            used[j] = 1
    else:
        li.append(1)


c = 1
#nCrmod
def ncr(n, r):
    if ( r<0 or r>n ):
        return 0
    return g1[n] * g2[r] % mod * g2[n-r] % mod
def npr(n, r):
    if ( r<0 or r>n ):
        return 0
    return g1[n] * g2[n-r] % mod
N = 1000
g1 = [1, 1] # 
g2 = [1, 1] #
inverse = [0, 1] #

for i in range( 2, N + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

dp = [[0] * (n + 1) for _ in range(len(li) + 1)]
dp[0][0] = 1
for leng in li:
    if leng == 1:
        for i in range(n):
            dp[c][i+1] = dp[c-1][i] * (n - i) % mod
    else:
        for i in range(n):
            dp[c][i+1] = dp[c-1][i] * (n - i) % mod
        for i in range(n+1-leng):
            dp[c][i+leng] += dp[c-1][i] * npr(n-i,leng) % mod
            dp[c][i+leng] %= mod
    c += 1
ans = 0
for i in range(n+1):
    ans += dp[-1][i]
    ans %= mod
print(ans)
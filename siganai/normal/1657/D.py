#!/usr/bin/env PyPy3

import bisect
#mod=10**9+7

import sys
input=sys.stdin.readline

n,C = map(int,input().split())
muldh = [0] * (C+1)
for _ in range(n):
    c,d,h = map(int,input().split())
    muldh[c] = max(muldh[c],d * h)
for i in range(1,C+1):
    muldh[i] = max(muldh[i],muldh[i-1])
    for j in range(2,C+1):
        if i * j > C:
            break
        muldh[i*j] = max(muldh[i*j],muldh[i] * j)
#print(muldh)
m = int(input())
ans = []
for _ in range(m):
    d,h = map(int,input().split())
    ind = bisect.bisect_left(muldh,d*h+1)
    if ind == C + 1:
        ans.append(-1)
    else:
        ans.append(ind)
print(*ans)
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
import os
from io import BytesIO, IOBase
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

INF = 1 << 31
def compress(mylist):
    B = list(set(mylist))
    B.sort()
    D = { v: i for i, v in enumerate(B) }
    return list(map(lambda v: D[v], mylist))
def solve():
    n,m=map(int,input().split())
    a = list(map(int,input().split()))
    a = compress(a)
    ma = max(a)
    prv = [-1] * (ma+1)
    cnt = [[] for _ in range(ma+1)]
    fli = [-1] * n
    now = -1
    for i in range(n):
        if prv[a[i]] == -1:
            prv[a[i]] = i
        else:
            now = max(now,prv[a[i]])
            prv[a[i]] = i
        fli[i] = now
        cnt[a[i]].append(i)
    mi = INF
    chk = [INF] * n
    for _ in range(m):
        l,r=map(int,input().split())
        if fli[r-1] < l - 1:
            continue
        else:
            chk[r-1] = min(chk[r-1],l-1)
            idx = bisect.bisect_left(fli,l-1)
            mi = min(mi,idx)
    if mi == INF:
        print(0)
        return
    for i in range(n-1)[::-1]:
        chk[i] = min(chk[i],chk[i+1])
    ans = n - mi
    for i in range(n-1)[::-1]:
        idx = bisect.bisect_right(cnt[a[i+1]],i+1)
        if idx != len(cnt[a[i+1]]):
            tmp = chk[cnt[a[i+1]][idx]]
            if tmp <= i + 1:
                break
        if idx > 1:
            tmp = chk[i+1]
            midx = bisect.bisect_left(cnt[a[i+1]],tmp)
            if midx < len(cnt[a[i+1]]):
                mi = min(mi,cnt[a[i+1]][midx])
        ans = min(ans,i+1-mi)
    print(ans)
    return 0
t = int(input())
for _ in range(t):
    solve()
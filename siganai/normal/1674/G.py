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

n,m=map(int,input().split())
g = [[] for _ in range(n)]
ab = [list(map(int,input().split())) for _ in range(m)]
inv = [0] * n
outv = [0] * n
for i in range(m):
    ab[i][0] -= 1
    ab[i][1] -= 1
    inv[ab[i][0]] += 1
    outv[ab[i][1]] += 1
s = set()
for a,b in ab:
    if inv[a] > 1 and outv[b] > 1:
        g[a].append(b)
    else:
        s.add((a,b))
for a,b in s:
    inv[a] -= 1;outv[b] -= 1

go = deque()
for i in range(n):
    if outv[i] <= 0:
        go.append(i)

dp = [0] * n
while go:
    now = go.pop()
    for nex in g[now]:
        dp[nex] = max(dp[nex],dp[now] + 1)
        outv[nex] -= 1
        if outv[nex] == 0:
            go.appendleft(nex)
print(max(dp) + 1)
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
rg = [[] for _ in range(n)]
for _ in range(m):
    a,b=map(int,input().split())
    a,b=a-1,b-1
    g[a].append(b)
    rg[b].append(a)
INF = 1 << 31
dist = [INF] * n
dist[-1] = 0

h = [(0,n-1)]
used = [0] * n
cnt = [0] * n
while h:
    now_cost, u = heappop(h)
    if now_cost != dist[u]:
        continue
    used[u] = 1
    for v in rg[u]:
        cnt[v] += 1
        if dist[v] > len(g[v]) - cnt[v] + now_cost + 1:
            dist[v] = len(g[v]) - cnt[v] + now_cost + 1
            heappush(h,(dist[v],v))
print(dist[0])
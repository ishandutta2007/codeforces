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
t = int(input())

for _ in range(t):
    n = int(input())
    p = list(map(int,input().split()))
    for i in range(n):
        if p[i] == i + 1:
            root = i
            break
    g = [[] for _ in range(n)]
    for i in range(n):
        if i == root:
            continue
        g[p[i] - 1].append(i)
        g[i].append(p[i] - 1)
    used = [0] * n
    groop = [-1] * n
    groop[root] = root
    d = defaultdict(list)
    d[root].append(root + 1)
    go = deque([root])
    while go:
        now = go.pop()
        used[now] = 1
        cnt = 0
        for nex in g[now]:
            if used[nex]:
                continue
            if cnt == 0:
                groop[nex] = groop[now]
                cnt = 1
            else:
                groop[nex] = nex
            d[groop[nex]].append(nex + 1)
            go.append(nex)
    print(len(d))
    for key in d:
        print(len(d[key]))
        print(*d[key])
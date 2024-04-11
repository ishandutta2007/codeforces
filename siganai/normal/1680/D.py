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

n,k = map(int,input().split())
a = list(map(int,input().split()))
l = [0] * (n+2)
r = [0] * (n+2)
for i in range(n-1,-1,-1):
    if a[i] != 0:
        l[i] = l[i+1] - a[i]
        r[i] = r[i+1] - a[i]
    else:
        l[i] = l[i+1] - k
        r[i] = r[i+1] + k
if not (l[0] <= 0 <= r[0]):
    print(-1)
    exit()
ans = 0

for j in range(n+2):
    za = [0]
    now = 0
    for i in range(n):
        if a[i] != 0:
            now += a[i]
        else:
            if i < j:
                now = max(l[i+1],now - k)
            else:
                now = min(r[i+1],now + k)
        za.append(now)
    ans = max(ans,max(za)-min(za)+1)

for j in range(n+2):
    za = [0]
    now = 0
    for i in range(n):
        if a[i] != 0:
            now += a[i]
        else:
            if i < j:
                now = min(r[i + 1], now + k)
            else:
                now = max(l[i + 1], now - k)
        za.append(now)
    ans = max(ans,max(za)-min(za)+1)
print(ans)
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
    a = list(map(int,input().split()))
    u1 = [0] * n
    u2 = [0] * n
    i = 0
    ans = 0
    re1 = 1
    re2 = n
    while i < n - 1:
        mi = a[i]
        ma = a[i]
        u1[a[i] - 1] = u2[a[i] - 1] = 1
        j = i + 1
        p = j
        while j < n:
            mi = min(a[j],mi)
            ma = max(a[j],ma)
            if mi < a[i] < ma:
                break
            else:
                if mi == a[j] or ma == a[j]:
                    for k in range(p,j+1):
                        u1[a[k] - 1] = u2[a[k] - 1] = 1
                    while re1 < n and u1[re1 - 1]:
                        re1 += 1
                    while re2 > 0 and u2[re2 - 1]:
                        re2 -= 1
                    p = j
                    if mi == a[i]:
                        if re2 < ma:
                            break
                    else:
                        if re1 > mi:
                            break
                j += 1
        ans += 1
        i = p
    print(ans)
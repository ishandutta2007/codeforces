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
t = int(input())
INF = 1 << 31
for _ in range(t):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    a.sort()
    pre = -1
    good = []
    cnt = 0
    for aa in a:
        if aa != pre:
            if cnt >= k:
                good.append(pre)
            pre = aa
            cnt = 1
        else:
            cnt += 1
    if cnt >= k:
        good.append(pre)
    ans = -1
    l = 0
    r = 0
    chk = [0] * len(good)
    for i,aa in enumerate(good):
        if chk[i]:
            continue
        cnt = 0
        now = i
        while now < len(good) and good[now] == aa + cnt:
            chk[now] = 1
            cnt += 1
            now += 1
        if ans < cnt:
            ans = cnt
            l = aa
            r = aa + cnt - 1
    if ans == -1:
        print(-1)
    else:
        print(l,r)
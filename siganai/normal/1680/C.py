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
for _ in range(t):
    s = input().rstrip()
    m0 = s.count('0')
    m1 = len(s) - m0
    now = s[0]
    c = 0
    li = []
    for i in range(len(s)):
        if now == s[i]:
            c += 1
        else:
            li.append([now,c])
            c = 1
            now = s[i]
    li.append([now,c])
    if len(li) <= 2:
        print(0)
        continue
    ans = m0
    r = 0
    oc = 0
    zc = 0
    cl = [[0] * (len(li) + 1) for _ in range(2)]
    for i in range(len(li))[::-1]:
        cl[0][i] = cl[0][i+1]
        cl[1][i] = cl[1][i+1]
        if li[i][0] == '1':
            cl[1][i] += li[i][1]
        else:
            cl[0][i] += li[i][1]
        ans = min(ans,max(cl[1][i],m0 - cl[0][i]))
    for i in range(len(li)):
        if li[i][0] == '1':
            oc += li[i][1]
        else:
            zc += li[i][1]
            r = max(r,i+1)
            nzc = m0 - cl[0][r] - zc
            noc = cl[1][r] + oc
            while r < len(li) and nzc < noc:
                if li[r][0] == '0':
                    nzc += li[r][1]
                else:
                    noc -= li[r][1]
                ans = min(ans,max(noc,nzc))
                r += 1
            r -= 1
    print(ans)
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

x = [1,1]
for i in range(60):
        x.append(x[-1] + x[-2])

cums = [0] + list(itertools.accumulate(x))
#print(cums)
#print(x)
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    su = sum(a)
    if not su in cums:
        print('NO')
    else:
        if n == 1:
            if su == 1:
                print('YES')
            else:
                print('NO')
            continue
        pos = 0
        for i in range(60):
            if cums[i] == su:
                pos = i
                break

        hp = [-aa for aa in a]
        heapify(hp)
        cur = -1
        for i in range(pos)[::-1]:
            now = heappop(hp)
            if (cur == -now):
                nnow = heappop(hp)
                nnow = -nnow
                if nnow < x[i]:
                    print('NO')
                    break
                nnow -= x[i]
                cur = nnow
                heappush(hp,now)
                heappush(hp,nnow)

            else:
                now = -now
                if now < x[i]:
                    print('NO')
                    break
                now -= x[i]
                cur = now
                heappush(hp,-now)
        else:
            print('YES')
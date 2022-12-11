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
    n,m = map(int,input().split())
    a = [list(map(int,input().split())) for _ in range(n)]
    if (n + m - 1) % 2:
        print('NO')
    else:
        dist1 = [[0] * m for _ in range(n)]
        dist2 = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if i > 0:
                    dist1[i][j] = dist1[i-1][j]
                    dist2[i][j] = dist2[i-1][j]
                if j > 0:
                    dist1[i][j] = max(dist1[i][j],dist1[i][j-1])
                    dist2[i][j] = max(dist2[i][j],dist2[i][j-1])
                if a[i][j] == 1:
                    dist1[i][j] += 1
                else:
                    dist2[i][j] += 1
        if dist1[-1][-1] >= (n + m - 1) // 2 and dist2[-1][-1] >= (n + m - 1) // 2:
            print('YES')
        else:
            print('NO')
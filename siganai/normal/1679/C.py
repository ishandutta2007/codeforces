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
class Bit:#0-indexed  1-indexed0-indexed
    def __init__(self, n):
        self.size = n + 1
        self.tree = [0] * (n + 2)
        self.depth = (n + 1).bit_length()

    def add(self, i, x):
        i += 1
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
 
    def sum(self, i):
        i += 1
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def lower_bound(self, x):
        """ xindex """
        sum_ = 0
        pos = 0
        for i in range(self.depth, -1, -1):
            k = pos + (1 << i)
            if k <= self.size and sum_ + self.tree[k] < x:
                sum_ += self.tree[k]
                pos += 1 << i
        return pos, sum_
n,q=map(int,input().split())
bit1 = Bit(n + 2)
bit2 = Bit(n + 2)
cnt1 = [0] * n
cnt2 = [0] * n
for _ in range(q):
    que = list(map(int,input().split()))
    if que[0] == 1:
        cnt1[que[1] - 1] += 1
        cnt2[que[2] - 1] += 1
        if cnt1[que[1] - 1] == 1:
            bit1.add(que[1],1)
        if cnt2[que[2] - 1] == 1:
            bit2.add(que[2],1)
    elif que[0] == 2:
        cnt1[que[1] - 1] -= 1
        cnt2[que[2] - 1] -= 1
        if cnt1[que[1] - 1] == 0:
            bit1.add(que[1],-1)
        if cnt2[que[2] - 1] == 0:
            bit2.add(que[2],-1)
    else:
        tmp1 = bit1.sum(que[3]) - bit1.sum(que[1] - 1)
        tmp2 = bit2.sum(que[4]) - bit2.sum(que[2] - 1)
        if tmp1 == que[3] - que[1] + 1 or tmp2 == que[4] - que[2] + 1:
            print('YES')
        else:
            print('NO')
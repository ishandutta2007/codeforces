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
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    l = [[0] * n for _ in range(n)]
    for i in range(1,n):
        tmp = 0
        for j in range(i):
            if a[i] > a[j]:
                tmp += 1
            l[i][j] = tmp
    for i in range(n):
        tmp = 0
        for j in range(i+1,n)[::-1]:
            if a[i] > a[j]:
                tmp += 1
            l[i][j] = tmp
    ans = 0
    for i in range(1,n-2):
        for j in range(i+1,n-1):
            ans += l[i][j+1] * l[j][i-1]
    print(ans)
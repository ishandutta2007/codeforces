#!/usr/bin/env PyPy3

from collections import Counter, defaultdict, deque
import itertools
import re
import math
from functools import reduce
import operator
import bisect
import heapq
import functools
mod=10**9+7
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
t=int(input())
for _ in range(t):
    n =int(input())
    s=input().rstrip()
    l = [[0,0,0]]
    pl = 0
    mi = 0
    ren = 0
    flg = 0
    for i in range(n):
        if s[i] == '+':
            pl += 1
            flg = 0
        else:
            mi += 1
            if flg:
                ren += 1
                flg = 0
            else:
                flg = 1
        l.append([pl,mi,ren])
    ans = 0
    bit1 = Bit(n)
    bit2 = Bit(n)
    bit3 = Bit(n)
    geta = -(-n // 2)
    for pl,mi,ren in l:
        pos = (mi-pl) // 3+geta
        if (mi - pl) % 3 == 1:
            ans += bit1.sum(pos) - bit1.sum(max(0,pos-ren-1))
            bit1.add(pos,1)
        elif (mi - pl) % 3 == 2:
            ans += bit2.sum(pos) - bit2.sum(max(0,pos-ren-1))
            bit2.add(pos,1)
        else:
            ans += bit3.sum(pos) - bit3.sum(max(0,pos-ren-1))
            bit3.add(pos,1)
    print(ans)
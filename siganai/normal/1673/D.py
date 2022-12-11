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
mod=10 ** 9 +7

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

def sieve(limit):
        if limit < 2:
            return []
    
        # primep[n]==True(2 * n) + 1 
        primep = [1] * ((limit - 1) // 2 + 1)
    
        primep[0] = 0
        for num in range(1, int((limit ** 0.5) - 1) // 2 + 1):
            if primep[num]:
                p = 2 * num + 1 
                for i in range(num + p, len(primep), p):
                    primep[i] = 0
    
        return [2] + [2 * p + 1 for p in range(len(primep)) if primep[p]]
def divisor(n):
    sq = n ** 0.5
    border = int(sq)
    table = []
    bigs = []
    for small in range(1, border+1):
        if n%small == 0:
            table.append(small)
            big = n//small
            bigs.append(big)
    if border == sq:#n
        bigs.pop()
    table += reversed(bigs)
    return table
t = int(input())
for _ in range(t):
    b,q,y=map(int,input().split())
    c,r,z=map(int,input().split())
    if r % q:
        print(0)
    else:
        if b > c or b + q * (y - 1) < c + r * (z - 1):
            print(0)
            continue
        if (b - c) % q:
            print(0)
            continue
        last = c + r * (z - 1)
        table = divisor(r)
        ans = 0
        if c - r < b or last + r > b + q * (y - 1):
            print(-1)
            continue
        for j in table:
            gcd_jq = math.gcd(j,q)
            if j * q // gcd_jq == r:
                ans += (r // j) ** 2
                ans %= mod
        print(ans)
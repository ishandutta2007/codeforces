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
INF = 1 << 60
t = int(input())
for _ in range(t):
    n = int(input())
    a = [list(map(int,input().split())) for _ in range(2)]
    dp = [[0] * n for _ in range(2)]
    for j in range(n):
        if j % 2 == 0:
            if j == 0:
                dp[1][0] = a[1][0] + 1
            else:
                dp[0][j] = max(dp[0][j-1],a[0][j]) + 1
                dp[1][j] = max(dp[0][j],a[1][j]) + 1
        else:
            dp[1][j] = max(dp[1][j-1],a[1][j]) + 1
            dp[0][j] = max(dp[1][j],a[0][j]) + 1

    ans = max(dp[0][-1],dp[1][-1])
    if n == 2:
        ans = min(ans,max(a[0][1] + 3,a[1][1] + 2,a[1][0] + 1))
        print(ans)
        continue
    od = INF
    ev = INF
    if n % 2:
        od = max(a[1][-1] + 2,a[0][-1] + 1,a[0][-2]) + 1
        ev = max(a[0][-2] + 4,a[0][-1] + 3,a[1][-1] + 2,a[1][-2] + 1,a[1][-3]) + 1
    else:
        od = max(a[1][-2] + 4,a[1][-1] + 3,a[0][-1] + 2,a[0][-2] + 1,a[0][-3]) + 1
        ev = max(a[0][-1] + 2,a[1][-1] + 1,a[1][-2]) + 1
    for j in range(n-1)[::-1]:
        if j % 2:
            od = max(od,a[1][j+1] + (n - j - 1) * 2 + 1,a[0][j] + 1,a[0][j+1] + 2)
            ans = min(ans,max(od,dp[1][j] + (n - j - 1) * 2 + 1))
            od = max(od,a[1][j] + (n - j) * 2) + 2
        else:
            ev = max(ev,a[0][j+1] + (n - j - 1) * 2 + 1,a[1][j] + 1,a[1][j+1] + 2)
            ans = min(ans,max(ev,dp[0][j] + (n - j - 1) * 2 + 1)) 
            ev = max(ev,a[0][j] + (n - j) * 2) + 2
    print(ans)
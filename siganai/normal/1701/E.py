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
T = int(input())
for _ in range(T):
    n,m = map(int,input().split())
    s = input().rstrip()
    t = input().rstrip()
    dp = [[INF] * (m+1) for _ in range(3)]
    dp[0][0] = 1
    dp[1][0] = 0
    for i in range(n):
        ndp = [[INF] * (m+1) for _ in range(3)]
        for k in range(2):
            for j in range(m+1):
                dp[k+1][j] = min(dp[k+1][j],dp[k][j])
        for j in range(m+1):
            ndp[0][j] = min(ndp[0][j],dp[0][j] + 2)
            ndp[2][j] = min(ndp[2][j],dp[2][j] + 1)
            if j < m:
                if s[i] == t[j]:
                    ndp[0][j+1] = min(ndp[0][j+1],dp[0][j]+1)
                    ndp[1][j+1] = min(ndp[1][j+1],dp[1][j])
                    ndp[2][j+1] = min(ndp[2][j+1],dp[2][j]+1)
        dp = ndp
    ans = min(dp[0][-1],dp[1][-1],dp[2][-1])
    if ans == INF:
        print(-1)
    else:
        print(ans)
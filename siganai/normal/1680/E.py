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
    n = int(input())
    s = [input().rstrip() for _ in range(2)]
    dp = [[0] * (n + 1) for _ in range(2)]
    l = -1
    for i in range(n):
        for j in range(2):
            if s[j][i] == '*':
                l = i
                break
        if l != -1:
            break
    r = -1
    for i in range(n)[::-1]:
        for j in range(2):
            if s[j][i] == '*':
                r = i
                break
        if r != -1:
            break
    for i in range(l,r+1):
        flg0 = 0
        flg1 = 0
        if i != l:
            dp[0][i+1] = dp[0][i] + 1
            dp[1][i+1] = dp[1][i] + 1
        '''
        if dp[0][i+1] > dp[1][i+1] + 1:
            dp[0][i+1] = dp[1][i+1] + 1
            flg0 = 1
        if dp[1][i+1] > dp[0][i+1] + 1:
            dp[1][i+1] = dp[0][i+1] + 1
            flg1 = 1
        '''
        if s[0][i] == '*':
            tmp1 = min(dp[0][i+1],dp[1][i+1]) + 1
        if s[1][i] == '*':
            tmp0 = min(dp[1][i+1],dp[0][i+1]) + 1
        if s[0][i] == '*':
            dp[1][i+1] = tmp1
        if s[1][i] == '*':
            dp[0][i+1] = tmp0
    print(min(dp[0][r+1],dp[1][r+1]))
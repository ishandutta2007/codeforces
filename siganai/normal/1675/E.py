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
orda = ord('a')
for _ in range(t):
    n,k=map(int,input().split())
    s = input().rstrip()
    ma = 0
    for ss in s:
        ma = max(ma,ord(ss) - orda)
    if ma <= k:
        print('a' * n)
    else:
        ma = 0
        ans = []
        flg = 0
        for ss in s:
            if flg == 0 and ord(ss) - orda <= k:
                ma = max(ma,ord(ss) - orda)
                ans.append('a')
            elif ord(ss) - orda <= k:
                if chr(ma + orda) >= ss:
                    ans.append(min(ans[0],ss))
                else:
                    ans.append(min(it,ss))
            elif flg == 0:
                flg = 1
                rem = k - ma
                up = ss
                it = chr(ord(ss) - rem)
                ans.append(chr(ord(ss) - rem))
            else:
                if ss <= up:
                    ans.append(min(it,ss))
                else:
                    ans.append(ss)
        print(''.join(ans))
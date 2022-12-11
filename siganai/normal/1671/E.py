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
mod=998244353

import sys
input=sys.stdin.readline
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
n=int(input())
m = 2 ** n
s=input().rstrip()
ans = [1] * (m+1)
st = [deque() for _ in range(m+1)]
for i in range(m//2,m,2):
    if s[i] == s[i-1]:
        ans[i//2] = 1
        st[i//2].append(s[i-1])
        st[i//2].append(s[i])
    else:
        ans[i//2] = 2
        st[i//2].append('A')
        st[i//2].append('B')
for i in range(2,m//2-1,2)[::-1]:
    #print(i,i+1)
    st[i+1].appendleft(s[i])
    st[i].appendleft(s[i-1])
    if st[i+1] == st[i]:
        ans[i//2] *= ans[i]
        ans[i//2] *= ans[i+1]
        ans[i//2] %= mod
    else:
        ans[i//2] *= ans[i]
        ans[i//2] *= ans[i+1]
        ans[i//2] %= mod
        ans[i//2] *= 2
        ans[i//2] %= mod
    if st[i+1] <= st[i]:
        while st[i+1]:
            p = st[i+1].popleft()
            st[i//2].append(p)
        while st[i]:
            p = st[i].popleft()
            st[i//2].append(p)
    else:
        while st[i]:
            p = st[i].popleft()
            st[i//2].append(p)
        while st[i+1]:
            p = st[i+1].popleft()
            st[i//2].append(p)
print(ans[1])
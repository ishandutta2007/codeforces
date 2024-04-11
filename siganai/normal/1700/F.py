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

n = int(input())
a = [list(map(int,input().split())) for _ in range(2)]
b = [list(map(int,input().split())) for _ in range(2)]
sa = 0
sb = 0
for i in range(2):
    for j in range(n):
        sa += a[i][j]
        sb += b[i][j]
if sa != sb:
    print(-1)
    exit()
a1 = deque()
a2 = deque()
b1 = deque()
b2 = deque()
ans = 0
for j in range(n):
    if a[0][j] == b[0][j] == 1:
        a[0][j] = b[0][j] = 0
    if a[1][j] == b[1][j] == 1:
        a[1][j] = b[1][j] = 0
    use1 = 0
    if a[0][j] == 1:
        if b1:
            p = b1.popleft()
            ans += j - p
            use1 = 1
    use2 = 0
    if a[1][j] == 1:
        if b2:
            p = b2.popleft()
            ans += j - p
            use2 = 1
    if a[0][j] and not use1:
        if b2:
            p = b2.popleft()
            ans += j - p + 1
        else:
            a1.append(j)
    if a[1][j] and not use2:
        if b1:
            p = b1.popleft()
            ans += j - p + 1
        else:
            a2.append(j)
    use3 = 0
    if b[0][j] == 1:
        if a1:
            p = a1.popleft()
            ans += j - p
            use3 = 1
    use4 = 0
    if b[1][j] == 1:
        if a2:
            p = a2.popleft()
            ans += j - p
            use4 = 1
    if b[0][j] and not use3:
        if a2:
            p = a2.popleft()
            ans += j - p + 1
        else:
            b1.append(j)
    if b[1][j] and not use4:
        if a1:
            p = a1.popleft()
            ans += j - p + 1
        else:
            b2.append(j)
    #print(a1,a2,b1,b2,j,ans)
print(ans)
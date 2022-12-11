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
p = list(map(int,input().split()))
INF = 1 << 31

ans = 0
l = 0
que = deque()
mi = INF
for r in range(n):
    if not que:
        que.append(p[r])
        ans += 1
    else:
        if que[-1] < p[r]:
            que.append(p[r])
            ans += r - l + 1
        else:
            if mi > que[-1]:
                mi = que.pop()
                if (not que) or que[-1] < p[r]:
                    que.append(p[r])
                    ans += r - l + 1
                else:
                    mi = p[r]
                    ans += r - l + 1
            else:
                if mi > p[r]:
                    mi = p[r]
                    ans += r - l + 1
                else:
                    que = deque()
                    ma = -INF
                    for ll in range(r+1)[::-1]:
                        if not que:
                            que.append(p[ll])
                        else:
                            if que[-1] > p[ll]:
                                que.append(p[ll])
                            else:
                                if ma < que[-1]:
                                    ma = que.pop()
                                    if (not que) or que[-1] > p[ll]:
                                        que.append(p[ll])
                                    else:
                                        ma = p[ll]
                                else:
                                    if ma < p[ll]:
                                        ma = p[ll]
                                    else:
                                        break
                        #print(que,ma)
                    l = ll + 1
                    ans += r - l + 1
                    que = deque()
                    mi = INF
                    for rr in range(l,r+1):
                        if not que:
                            que.append(p[rr])
                            #ans += 1
                        else:
                            if que[-1] < p[rr]:
                                que.append(p[rr])
                                #ans += r - l + 1
                            else:
                                if mi > que[-1]:
                                    mi = que.pop()
                                    if (not que) or que[-1] < p[rr]:
                                        que.append(p[rr])
                                        #ans += r - l + 1
                                    else:
                                        mi = p[rr]
                                        #ans += r - l + 1
                                else:
                                    mi = p[rr]
    #print(que,mi,ans)

print(ans)
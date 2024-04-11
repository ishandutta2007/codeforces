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
    x = list(map(int,input().split()))
    now = x[0]
    li = []
    cnt = 0
    for i in range(n):
        if x[i] == now:
            cnt += 1
        else:
            li.append([now,cnt,i-cnt,i])
            now = x[i]
            cnt = 1
    li.append([now,cnt,n-cnt,n])
    ma = 0
    ansl = 0
    ansr = 0
    chk = [0] * len(li)
    for i in range(len(li)):
        if chk[i]: continue
        now,cnt,l,r=li[i]
        if cnt > ma:
            ma = cnt
            ansl = l
            ansr = r
        dec = 0
        ma_cnt = cnt
        tmp = []
        for j in range(i+1,len(li)):
            if now != li[j][0]:
                dec += li[j][1]
                if cnt <= dec:
                    break
            else:
                tmp.append(j)
                cnt += li[j][1] - dec
                dec = 0
                if cnt > ma:
                    ma = cnt
                    ansl = l
                    ansr = li[j][3]
                if cnt > ma_cnt:
                    ma_cnt = cnt
                    while tmp:
                        p = tmp.pop()
                        chk[p] = 1
    print(x[ansl],ansl+1,ansr)
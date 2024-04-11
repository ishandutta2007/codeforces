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
from tkinter import N
import typing
mod=1000000007
 
#import sys
#input = sys.stdin.readline

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
INF = 1 << 31
for _ in range(t):
    n = int(input())
    s = input().rstrip()
    li = [0]
    tmp = 0
    for i in range(2*n):
        if s[i] == '(':
            tmp += 1
        else:
            tmp -= 1
        li.append(tmp)
    if min(li) >= 0:
        print(0)
        continue
    else:
        lmaidx = 0
        for i in range(2*n+1):
            if li[i] < 0:
                break
            if li[lmaidx] < li[i]:
                lmaidx = i           
        rmaidx = 2*n
        for i in range(2*n+1)[::-1]:
            if li[i] < 0:
                break
            if li[rmaidx] < li[i]:
                rmaidx = i
        maidx = 0
        for i in range(2*n+1):
            if li[maidx] < li[i]:
                maidx = i
        #print(li[lmaidx] , li[rmaidx] , li[maidx])
        if li[lmaidx] + li[rmaidx] - li[maidx] >= 0:
            print(1)
            print(lmaidx+1,rmaidx)
        else:
            print(2)
            print(1,maidx)
            print(maidx+1,2*n)
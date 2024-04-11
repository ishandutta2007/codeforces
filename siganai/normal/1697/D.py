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
ans = [0] * n
now = -1
ml = 0
li = []
chk = [0] * n
for i in range(n):
    l = 0
    r = i + 1
    print('?',2,l+1,r,flush = True)
    cnt = int(input())
    if len(li) < cnt:
        now += 1
        ans[i] = now
        li.append(i)
        chk[i] = 1       
        continue
    l = 0
    r = len(li)
    li.sort()
    #print(li)
    while r - l > 1:
        mid = (r + l) // 2
        print('?',2,li[mid]+1,i+1,flush = True)
        tmp = int(input())
        if tmp > len(li) - mid:
            r = mid
        else:
            l = mid

    ans[i] = ans[li[l]]
    li[l] = i
    #print(li)
#print(ans)
now = -1
st = [''] * n

for i in range(n):
    if chk[i]:
        now += 1
        print('?',1,i+1,flush = True)
        s = input().rstrip()
        st[i] = s
for i in range(n):
    if chk[i]:
        for j in range(i+1,n):
            if ans[i] == ans[j]:
                st[j] = st[i]
print('!',''.join(st))
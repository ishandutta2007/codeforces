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
mod=10**9+7

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

t = int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    if a == b:
        print('YES')
    else:
        used = [0] * (n + 1)
        if a[-1] != b[-1]:
            print('NO')
            continue
        now = n - 2
        flg = 0
        for i in range(n-1)[::-1]:
            if now >= 0:
                if a[i] != b[now]:
                    while True:
                        if now >= 0:
                            if a[i] == b[now]:
                                now -= 1
                                break
                            if b[now] == b[now + 1]:
                                used[b[now]] += 1
                                now -= 1
                            elif used[a[i]] > 0:
                                used[a[i]] -= 1
                                break
                            else:
                                flg = 1
                                break
                        elif used[a[i]] > 0:
                            used[a[i]] -= 1
                            break
                        else:
                            flg = 1
                            break
                    if flg:
                        print('NO')
                        break
                else:
                    now -= 1
            else:
                if used[a[i]] > 0:
                    used[a[i]] -= 1
                else:
                    print('NO')

                    break
        else:
            print('YES')
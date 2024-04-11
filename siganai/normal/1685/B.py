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
for _ in range(t):
    a,b,c,d = map(int,input().split())
    s = input().rstrip()
    acnt = s.count('A')
    bcnt = len(s) - acnt
    if a + c + d == acnt and b + c + d == bcnt:
        com = 0
        ab = []
        ba = []
        now = s[0]
        l = 0
        for i in range(1,len(s)):
            if now == s[i]:
                if i - l > 1:
                    if (i - l) % 2 == 0:
                        if now == 'A':
                            ba.append((i - l) // 2)
                        else:
                            ab.append((i - l) // 2)
                    else:
                        com += (i - l - 1) // 2
                l = i
                #print(ab,ba,com)
            else:
                now = s[i]
        if len(s) - l > 1:
            if (len(s) - l) % 2 == 0:
                if now == 'A':
                    ba.append((len(s) - l) // 2)
                else:
                    ab.append((len(s) - l) // 2)
            else:
                com += (len(s) - l - 1) // 2
        ab.sort(reverse = True)
        ba.sort(reverse = True)
        while ab and c:
            tmp = ab.pop()
            if c >= tmp:
                c -= tmp
            else:
                ab.append(tmp-c)
                c = 0
        while ba and d:
            tmp = ba.pop()
            if d >= tmp:
                d -= tmp
            else:
                ba.append(tmp-d)
                d = 0
        if c and d:
            if c + d <= com:
                print('YES')
            else:
                print('NO')
        elif c:
            rem = 0
            for cnt in ba:
                rem += cnt - 1
            if c <= com + rem:
                print('YES')
            else:
                print('NO')
        elif d:
            rem = 0
            for cnt in ab:
                rem += cnt - 1
            if d <= com + rem:
                print('YES')
            else:
                print('NO')
        else:
            print('YES')
    else:
        print('NO')
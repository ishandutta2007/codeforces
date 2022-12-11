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
mod=10 ** 9 + 7
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

n,l,r,z=map(int,input().split())


#nCrmod
def cmb(n, r):
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] % mod * g2[n-r] % mod

N = 10 ** 3
g1 = [1, 1] # 
g2 = [1, 1] #
inverse = [0, 1] #

for i in range( 2, N + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

def solve(z,r):
    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(61):
        ndp = [0] * (n + 1)
        for j in range(n + 1):
            for cnt in range(z&1,n+1,2):
                if j + cnt > r:
                    break
                d = 0
                if r & 1 == 0 and (j + cnt) % 2 == 1:
                    d = 1
                ndp[(j + cnt) // 2 + d] += dp[j] * cmb(n,cnt) % mod
                ndp[(j + cnt) // 2 + d] %= mod
        z //= 2
        r //= 2
        dp = ndp
    return dp[0]
print((solve(z,r) - solve(z,l-1)) % mod)
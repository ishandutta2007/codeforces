import bisect
import functools
import heapq
import itertools
import math
import operator
import re
import sys
import typing
from collections import Counter, defaultdict, deque
from functools import reduce
import sys
input=sys.stdin.readline
'''
INF = 1 << 31
r,g,b=map(int,input().split())
dp = [[INF] * 901 for _ in range(1000)]
for i in range(900):
    dp[i][0] = 0
for i in range(1000):
    pos = i - 500
    for j in range(1,r+g+b+1):
        if j <= r:
            dp[i][j] = min(dp[i][j],dp[i-1][j-1]+abs(pos+100))
        elif j <= r + g:
            dp[i][j] = min(dp[i][j],dp[i-1])
'''
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
n,m=map(int,input().split())
p=list(map(int,input().split()))
cumsum = list(itertools.accumulate(p))
x=list(map(int,input().split()))
x.sort()
ans = 0
for i in range(m+1):
    if i == 0:
        pos = (x[0] - 1) // 100
        ans = max(ans,sum(p[:min(pos+1,n)]))
        #print(ans)
    elif i == m:
        pos = x[-1] // 100
        ans = max(ans,cumsum[-1]-cumsum[min(pos,n-1)])
    else:
        dis = x[i] - x[i-1]
        f = (dis - 1) // 2
        ff = f // 100
        pre = x[i-1] // 100
        suf = (x[i] - 1) // 100
        for j in range(pre,suf):
            ans = max(ans,cumsum[min(n-1,suf,j+ff+1)]-cumsum[min(n-1,j)])

print(ans)
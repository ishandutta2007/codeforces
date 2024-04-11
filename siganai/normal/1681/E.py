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


import typing
class SegTree:
    def __init__(self,
                 op: typing.Callable[[typing.Any, typing.Any], typing.Any],
                 e: typing.Any,
                 v: typing.Union[int, typing.List[typing.Any]]) -> None:
        self._op = op
        self._e = e

        if isinstance(v, int):
            v = [e] * v

        self._n = len(v)
        self._log = self._n.bit_length()
        self._size = 1 << self._log
        self._d = [e] * (2 * self._size)

        for i in range(self._n):
            self._d[self._size + i] = v[i]
        for i in range(self._size - 1, 0, -1):
            self._update(i)

    def set(self, p: int, x: typing.Any) -> None:
        assert 0 <= p < self._n

        p += self._size
        self._d[p] = x
        for i in range(1, self._log + 1):
            self._update(p >> i)

    def get(self, p: int) -> typing.Any:
        assert 0 <= p < self._n

        return self._d[p + self._size]

    def prod(self, left: int, right: int) -> typing.Any:
        assert 0 <= left <= right <= self._n
        sml = self._e
        smr = self._e
        left += self._size
        right += self._size

        while left < right:
            if left & 1:
                sml = self._op(sml, self._d[left])
                left += 1
            if right & 1:
                right -= 1
                smr = self._op(self._d[right], smr)
            left >>= 1
            right >>= 1

        return self._op(sml, smr)

    def all_prod(self) -> typing.Any:
        return self._d[1]

    def max_right(self, left: int,
                  f: typing.Callable[[typing.Any], bool]) -> int:
        assert 0 <= left <= self._n
        assert f(self._e)

        if left == self._n:
            return self._n

        left += self._size
        sm = self._e

        first = True
        while first or (left & -left) != left:
            first = False
            while left % 2 == 0:
                left >>= 1
            if not f(self._op(sm, self._d[left])):
                while left < self._size:
                    left *= 2
                    if f(self._op(sm, self._d[left])):
                        sm = self._op(sm, self._d[left])
                        left += 1
                return left - self._size
            sm = self._op(sm, self._d[left])
            left += 1

        return self._n

    def min_left(self, right: int,
                 f: typing.Callable[[typing.Any], bool]) -> int:
        assert 0 <= right <= self._n
        assert f(self._e)

        if right == 0:
            return 0

        right += self._size
        sm = self._e

        first = True
        while first or (right & -right) != right:
            first = False
            right -= 1
            while right > 1 and right % 2:
                right >>= 1
            if not f(self._op(self._d[right], sm)):
                while right < self._size:
                    right = 2 * right + 1
                    if f(self._op(self._d[right], sm)):
                        sm = self._op(self._d[right], sm)
                        right -= 1
                return right + 1 - self._size
            sm = self._op(self._d[right], sm)

        return 0

    def _update(self, k: int) -> None:
        self._d[k] = self._op(self._d[2 * k], self._d[2 * k + 1])
def op(x,y):
    return [min(x[0] + y[0],x[1] + y[2]),min(x[0] + y[1],x[1] + y[3]),min(x[2] + y[0],x[3] + y[2]),min(x[2] + y[1],x[3] + y[3])]
INF = 1 << 60
e = [0,INF,INF,0]

n = int(input())
door = []
for _ in range(n-1):
    d1x,d1y,d2x,d2y = map(int,input().split())
    d1x -= 1
    d1y -= 1
    d2x -= 1
    d2y -= 1
    door.append([d1x,d1y,d2x,d2y])
a = [[0] * 4 for _ in range(n-2)]
for i in range(n-2):
    a[i][0] = abs(door[i][0] + 1 - door[i+1][0]) + abs(door[i][1] - door[i+1][1]) + 1
    a[i][1] = abs(door[i][0] + 1 - door[i+1][2]) + abs(door[i][1] - door[i+1][3]) + 1
    a[i][2] = abs(door[i][2] - door[i+1][0]) + abs(door[i][3] - door[i+1][1] + 1) + 1
    a[i][3] = abs(door[i][2] - door[i+1][2]) + abs(door[i][3] - door[i+1][3] + 1) + 1
seg = SegTree(op,e,a)

m = int(input())
for i in range(m):
    sx,sy,gx,gy=map(int,input().split())
    sx -= 1
    sy -= 1
    gx -= 1
    gy -= 1
    p1 = max(sx,sy)
    p2 = max(gx,gy)
    if p1 == p2:
        print(abs(sx - gx) + abs(sy - gy))
    else:
        if p1 > p2:
            sx,gx=gx,sx
            sy,gy=gy,sy
            p1,p2=p2,p1
        '''
        if p2 == p1 + 1:
            ans = INF
            ans = min(ans, abs(sx - door[p1][0]) + abs(sy - door[p1][1]) + 1 + abs(door[p1][0] + 1 - gx) + abs(door[p1][1] - gy))
            ans = min(ans, abs(sx - door[p1][2]) + abs(sy - door[p1][3]) + 1 + abs(door[p1][2] - gx) + abs(door[p1][3] + 1 - gy))
            print(ans)
        '''
        R = seg.prod(p1,p2 - 1)
        ans = INF
        ans = min(ans,abs(sx - door[p1][0]) + abs(sy - door[p1][1]) + R[0] + 1 + abs(gx - door[p2 - 1][0] - 1) + abs(gy - door[p2 - 1][1]))
        ans = min(ans,abs(sx - door[p1][0]) + abs(sy - door[p1][1]) + R[1] + 1 + abs(gx - door[p2 - 1][2]) + abs(gy - door[p2 - 1][3] - 1))
        ans = min(ans,abs(sx - door[p1][2]) + abs(sy - door[p1][3]) + R[2] + 1 + abs(gx - door[p2 - 1][0] - 1) + abs(gy - door[p2 - 1][1]))
        ans = min(ans,abs(sx - door[p1][2]) + abs(sy - door[p1][3]) + R[3] + 1 + abs(gx - door[p2 - 1][2]) + abs(gy - door[p2 - 1][3] - 1))
        print(ans)
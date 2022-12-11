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
n,k=map(int,input().split())
b=list(map(int,input().split()))
class LazySegTree:
    def __init__(self, op, e, mapping, composition, _id, v): #v:
        self._op = op
        self._e = e
        self._mapping = mapping
        self._composition = composition
        self._id = _id
 
        if isinstance(v, int):
            v = [e]*v
 
        self._n = len(v)
        self._log = (self._n-1).bit_length()
        self._size = 1 << self._log
        self._d = [self._e]*(2*self._size)
        self._lz = [self._id]*self._size
        for i in range(self._n):
            self._d[self._size+i] = v[i]
        for i in range(self._size-1, 0, -1):
            self._update(i)
 
    def set(self, p, x):
        p += self._size
        for i in range(self._log, 0, -1):
            self._push(p >> i)
        self._d[p] = x
        for i in range(1, self._log+1):
            self._update(p >> i)
 
    def get(self, p):
        p += self._size
        for i in range(self._log, 0, -1):
            self._push(p >> i)
        return self._d[p]
 
    def prod(self, left, right):
        if left == right:
            return self._e
 
        left += self._size
        right += self._size
 
        for i in range(self._log, 0, -1):
            if ((left >> i) << i) != left:
                self._push(left >> i)
            if ((right >> i) << i) != right:
                self._push(right >> i)
 
        sml = self._e
        smr = self._e
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
 
    def all_prod(self):
        return self._d[1]
 
    def apply(self, left, right, f):
        if right is None:
            p = left
            p += self._size
            for i in range(self._log, 0, -1):
                self._push(p >> i)
            self._d[p] = self._mapping(f, self._d[p])
            for i in range(1, self._log+1):
                self._update(p >> i)
        else:
            if left == right:
                return
 
            left += self._size
            right += self._size
 
            for i in range(self._log, 0, -1):
                if ((left >> i) << i) != left:
                    self._push(left >> i)
                if ((right >> i) << i) != right:
                    self._push((right-1) >> i)
 
            l2 = left
            r2 = right
            while left < right:
                if left & 1:
                    self._all_apply(left, f)
                    left += 1
                if right & 1:
                    right -= 1
                    self._all_apply(right, f)
                left >>= 1
                right >>= 1
            left = l2
            right = r2
 
            for i in range(1, self._log+1):
                if ((left >> i) << i) != left:
                    self._update(left >> i)
                if ((right >> i) << i) != right:
                    self._update((right-1) >> i)
 
    def max_right(self, left, g):
        if left == self._n:
            return self._n
 
        left += self._size
        for i in range(self._log, 0, -1):
            self._push(left >> i)
 
        sm = self._e
        first = True
        while first or (left & -left) != left:
            first = False
            while left%2 == 0:
                left >>= 1
            if not g(self._op(sm, self._d[left])):
                while left < self._size:
                    self._push(left)
                    left *= 2
                    if g(self._op(sm, self._d[left])):
                        sm = self._op(sm, self._d[left])
                        left += 1
                return left-self._size
            sm = self._op(sm, self._d[left])
            left += 1
 
        return self._n
 
    def min_left(self, right, g):
        if right == 0:
            return 0
 
        right += self._size
        for i in range(self._log, 0, -1):
            self._push((right-1) >> i)
 
        sm = self._e
        first = True
        while first or (right & -right) != right:
            first = False
            right -= 1
            while right > 1 and right%2:
                right >>= 1
            if not g(self._op(self._d[right], sm)):
                while right < self._size:
                    self._push(right)
                    right = 2*right+1
                    if g(self._op(self._d[right], sm)):
                        sm = self._op(self._d[right], sm)
                        right -= 1
                return right+1-self._size
            sm = self._op(self._d[right], sm)
 
        return 0
 
    def _update(self, k):
        self._d[k] = self._op(self._d[2*k], self._d[2*k+1])
 
    def _all_apply(self, k, f):
        self._d[k] = self._mapping(f, self._d[k])
        if k < self._size:
            self._lz[k] = self._composition(f, self._lz[k])
 
    def _push(self, k):
        self._all_apply(2*k, self._lz[k])
        self._all_apply(2*k+1, self._lz[k])
        self._lz[k] = self._id
INF = 1 << 31
def op(x, y):
    #print(x,y)
    return x[0]+y[0],min(x[1],y[1]),max(x[2],y[2])
e = (0,INF,-INF)

def mapping(f, x):
    return x[0] + (f[0] * (x[1] + x[2] - 1) + f[1] * 2) * (x[2] - x[1]) // 2,x[1],x[2]
def composition(f, g):
    return f[0] + g[0],f[1] + g[1]
 
_id = (0,0)
v = []
for i in range(n):
    v.append((b[i],i,i+1))
lst = LazySegTree(op,e,mapping,composition,_id,v)
ans = 0
for i in range(k-1,n)[::-1]:
    x = lst.get(i)
    #print(x)
    if x[0] > 0:
        tmp = -(-x[0] // k)
        ans += tmp
        lst.apply(i-k+1,i+1,(-tmp,-tmp+tmp*(i-k+1)))

ma = 0
for i in range(k-1):
    x = lst.get(i)
    #print(x[0])
    ma = max(ma,-(-x[0] // (i+1)))
print(ans+ma)
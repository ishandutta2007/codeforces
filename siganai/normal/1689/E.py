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
class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        now = x
        tmpl = []
        while self.parents[now] >= 0:
            tmpl.append(now)
            now = self.parents[now]
        for xx in tmpl:
            self.parents[xx] = now
        return now

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return x

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x
        return x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):#O(n)all_group_members
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        group_members = defaultdict(list)
        for member in range(self.n):
            group_members[self.find(member)].append(member)
        return group_members

    def __str__(self):
        return '\n'.join(f'{r}: {m}' for r, m in self.all_group_members().items())

def connected(n):
    g = [[] for _ in range(31)]
    vis = [0] * 31
    m = 0
    for i in range(n):
        m |= a[i]
        prv = -1
        for j in range(31):
            if a[i] >> j & 1:
                if prv != -1:
                    g[prv].append(j)
                    g[j].append(prv)
                prv = j
    for j in range(31):
        if m >> j & 1:
            go = deque([j])
            while go:
                now = go.pop()
                vis[now] = 1
                for nex in g[now]:
                    if vis[nex]:continue
                    vis[nex] = 1
                    go.appendleft(nex)
            break
    for j in range(31):
        if m >> j & 1 and vis[j] == 0:
            return False
    return True

t = int(input())
for ii in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    ans = 0
    for i in range(n):
        if a[i] == 0:
            a[i] += 1
            ans += 1
    uf = UnionFind(n)
    flg = 0
    for i in range(n):
        if a[i] % 2:
            flg = 1
        for j in range(i+1,n):
            if a[i] & a[j]:
                uf.union(i,j)
    size = uf.group_count()
    all_group = uf.all_group_members()
    if size == 1:
        print(ans)
        print(*a)
        continue
    ok = False
    for i in range(n):
        a[i] += 1
        if connected(n):
            print(ans + 1)
            print(*a)
            ok = True
            break
        else:
            a[i] -= 1
    if ok:continue
    for i in range(n):
        a[i] -= 1
        if connected(n):
            print(ans + 1)
            print(*a)
            ok = True
            break
        else:
            a[i] += 1
    if ok:continue
        
            
    li = []
    for key in all_group.keys():
        flg = 0
        ma = key
        for val in all_group[key]:
            if a[ma] & -a[ma] < a[val] & -a[val]:
                ma = val
        li.append([ma,a[ma] & -a[ma]])
    li.sort(key = operator.itemgetter(1),reverse=True)
    uf = UnionFind(n)
    for id,_ in li:
        if a[id] > 1:
            a[id] -= 1
            ans += 1
            break
    for i in range(n):
        for j in range(i+1,n):
            if a[i] & a[j]:
                uf.union(i,j)
    size = uf.group_count()
    all_group = uf.all_group_members()
    for key in all_group.keys():
        for val in all_group[key]:
            if a[val] % 2:
                break
        else:
            a[key] += 1
            ans += 1
    print(ans)
    print(*a)
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
class LcaDoubling:

    def __init__(self, n, links, root=0):
        self.depths = [-1] * n
        self.distances = [-1] * n
        prev_ancestors = self._init_dfs(n, links, root)
        self.ancestors = [prev_ancestors]
        max_depth = max(self.depths)
        d = 1
        while d < max_depth:
            next_ancestors = [prev_ancestors[p] for p in prev_ancestors]
            self.ancestors.append(next_ancestors)
            d <<= 1
            prev_ancestors = next_ancestors
 
    def _init_dfs(self, n, links, root):
        q = [(root, -1, 0, 0)]
        direct_ancestors = [-1] * (n + 1)  
        while q:
            v, p, dep, dist = q.pop()
            direct_ancestors[v] = p
            self.depths[v] = dep
            self.distances[v] = dist
            q.extend((u, v, dep + 1, dist + w) for u, w in links[v] if u != p)
        return direct_ancestors
 
    def get_lca(self, u, v):
        du, dv = self.depths[u], self.depths[v]
        if du > dv:
            u, v = v, u
            du, dv = dv, du
        tu = u
        tv = self.upstream(v, dv - du)
        if u == tv:
            return u
        for k in range(du.bit_length() - 1, -1, -1):
            mu = self.ancestors[k][tu]
            mv = self.ancestors[k][tv]
            if mu != mv:
                tu = mu
                tv = mv
        lca = self.ancestors[0][tu]
        assert lca == self.ancestors[0][tv]
        return lca
 

    def get_distance(self, u, v):
        lca = self.get_lca(u, v)
        return self.distances[u] + self.distances[v] - 2 * self.distances[lca]
 
    def upstream(self, v, k):
        i = 0
        while k:
            if k & 1:
                v = self.ancestors[i][v]
            k >>= 1
            i += 1
        return v
def EulerTour(n, X, i0):
    done = [0] * n
    par = [-1] * n
    Q = deque([~i0, i0]) # 
    ET = []
    while Q:
        i = Q.pop()
        if i >= 0: # 
            done[i] = 1
            ET.append(i)
            for a,_ in X[i]:
                if done[a]: continue
                par[a] = i
                Q.append(~a) # 
                Q.append(a) # 
 
        else: # 
            i = ~i
            #ET.append(i)
 
    return ET
t = int(input())
for _ in range(t):
    space = input().rstrip()
    n,k=map(int,input().split())
    x,y = map(int,input().split())
    x -= 1
    y -= 1
    work = list(map(int,input().split()))
    g = [[] for _ in range(n)]
    for _ in range(n-1):
        a,b=map(int,input().split())
        a,b=a-1,b-1
        g[a].append([b,1])
        g[b].append([a,1])
    lca = LcaDoubling(n,g,x)
    ET = EulerTour(n,g,x)
    p = [0] * n
    for i in range(n):
        p[ET[i]] = i
    li = [x,y]
    for i in range(k):
        li.append(work[i]-1)
    ans = 0
    li.sort(key = lambda x:p[x])
    #print(li)
    for i in range(k+2):
        ans += lca.get_distance(li[i],li[i-1])
        #print(ans)
    ans -= lca.get_distance(x,y)
    print(ans)
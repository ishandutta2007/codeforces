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

n,m=map(int,input().split())
a = [list(map(int,input().split())) for _ in range(n)]
col = [0] * (n * m + 1)
row = [0] * (n * m + 1)
li = []
dx = [1,-1,0,0]
dy = [0,0,1,-1]
for i in range(n):
    for j in range(m):
        col[a[i][j]] = j
        row[a[i][j]] = i
        if a[i][j] == 1:
            continue
        flg = 0
        for k in range(4):
            ni,nj=i+dx[k],j+dy[k]
            if 0 <= ni < n and 0 <= nj < m:
                if a[ni][nj] < a[i][j]:
                    flg = 1
                    break
        if not flg:
            li.append(a[i][j])
if not li:
    print(0)
    exit()
li.sort()
ans = 0
it = li[0]
cit = col[it]
rit = row[it]
chk = li[1:]
for k in range(4):
    nx,ny = rit + dx[k],cit + dy[k]
    if 0 <= nx < n and 0 <= ny < m:
        for num in range(1,it):
            ncol = col[num]
            nrow = row[num]
            a[nrow][ncol],a[nx][ny] = a[nx][ny],a[nrow][ncol]
            flg = 1
            for kk in range(4):
                cx,cy = nrow + dx[kk],ncol + dy[kk]
                if 0 <= cx < n and 0 <= cy < m:
                    if a[cx][cy] == 1:continue
                    for kkk in range(4):
                        ncx,ncy = cx + dx[kkk],cy + dy[kkk]
                        if 0 <= ncx < n and 0 <= ncy < m:
                            if a[ncx][ncy] < a[cx][cy]:
                                break
                    else:
                        flg = 0
                        break
            if flg and num != 1:
                for kk in range(4):
                    cx,cy = nx + dx[kk],ny + dy[kk]
                    if 0 <= cx < n and 0 <= cy < m:
                        if a[cx][cy] < a[nx][ny]:
                            break
                else:
                    flg = 0
            if flg:
                for j in chk:
                    px,py = row[j],col[j]
                    for kk in range(4):
                        cx,cy = px + dx[kk],py + dy[kk]
                        if 0 <= cx < n and 0 <= cy < m:
                            if a[cx][cy] < a[px][py]:
                                break
                    else:
                        flg = 0
                        break
            if flg and num == 1:
                for kk in range(4):
                    cx,cy = nrow + dx[kk],ncol + dy[kk]
                    if 0 <= cx < n and 0 <= cy < m:
                        if a[nrow][ncol] > a[cx][cy]:
                            break
                else:
                    flg = 0
            ans += flg
            a[nrow][ncol],a[nx][ny] = a[nx][ny],a[nrow][ncol]

for i in range(n):
    for j in range(m):
        if rit == i and cit == j:continue
        a[rit][cit],a[i][j] = a[i][j],a[rit][cit]
        flg = 1
        for jj in chk:
            px,py = row[jj],col[jj]
            for kk in range(4):
                cx,cy = px + dx[kk],py + dy[kk]
                if 0 <= cx < n and 0 <= cy < m:
                    if a[cx][cy] < a[px][py]:
                        break
            else:
                #print('E')
                flg = 0
                break
        if flg:
            for k in range(4):
                ni,nj = i + dx[k],j + dy[k]
                if 0 <= ni < n and 0 <= nj < m:
                    if a[ni][nj] == 1:continue
                    for kk in range(4):
                        nni,nnj = ni + dx[kk],nj + dy[kk]
                        if 0 <= nni < n and 0 <= nnj < m:
                            if a[nni][nnj] < a[ni][nj]:
                                break
                    else:
                        #print('A')
                        flg = 0
                        break
        if flg:
            for k in range(4):
                ni,nj = i + dx[k],j + dy[k]
                if 0 <= ni < n and 0 <= nj < m:
                    if a[ni][nj] < a[i][j]:
                        break
            else:
                #print('B')
                flg = 0
        if flg:
            for k in range(4):
                ni,nj = rit + dx[k],cit + dy[k]
                if 0 <= ni < n and 0 <= nj < m:
                    if a[ni][nj] == 1:continue
                    for kk in range(4):
                        nni,nnj = ni + dx[kk],nj + dy[kk]
                        if 0 <= nni < n and 0 <= nnj < m:
                            if a[nni][nnj] < a[ni][nj]:
                                break
                    else:
                        #print('C')
                        flg = 0
                        break
        if flg and a[rit][cit] != 1:
            for k in range(4):
                ni,nj = rit + dx[k],cit + dy[k]
                if 0 <= ni < n and 0 <= nj < m:
                    if a[ni][nj] < a[rit][cit]:
                        break
            else:
                flg = 0
        ans += flg
        a[rit][cit],a[i][j] = a[i][j],a[rit][cit]
if ans:
    print(1,ans)
else:
    print(2)
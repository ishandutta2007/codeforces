from collections import Counter, defaultdict, deque
from functools import reduce
import sys
input=sys.stdin.readline
n=int(input())
d1 = defaultdict(int)
xy = []
for i in range(n):
    x,y = map(int,input().split())
    xy.append((x,y))
    d1[(x,y)] = ~i
dx = [1,0,-1,0]
dy = [0,1,0,-1]
ans = [[0,0] for _ in range(n)]
dist = [1] * n
num = 10 ** 6
go = deque()
for i in range(n):
    x,y = xy[i]
    for j in range(4):
        nx,ny = x + dx[j],y + dy[j]
        if d1[(nx,ny)] == 0:
            ans[i] = nx,ny
            dist[i] = 0
            go.appendleft(i)
            break
while go:
    nowi = go.pop()
    nowx,nowy = xy[nowi][0],xy[nowi][1]
    for i in range(4):
        nexx,nexy = nowx + dx[i],nowy + dy[i]
        if d1[(nexx,nexy)] == 0:
            continue
        nexi = ~d1[(nexx,nexy)]
        if dist[nexi]:
            dist[nexi] = 0
            ans[nexi] = ans[nowi]
            go.appendleft(nexi)
for x,y in ans:
    print(x,y)
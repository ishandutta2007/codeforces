from sys import setrecursionlimit
setrecursionlimit(30000)
maxl = -1
def dfs(v, lvl):
    used[v] = True
    global maxl
    if lvl > maxl:
        maxl = lvl
    for u in ch[v]:
        dfs(u, lvl + 1)

n = int(input())
used = [False] * n
p = [int(input()) - 1 for i in range(n)]
ch = [[] for i in range(n)]
for i in range(n):
    if p[i] != -2:
        ch[p[i]].append(i)
for i in range(n):
    if p[i] == -2:
        dfs(i, 1)
print(maxl)
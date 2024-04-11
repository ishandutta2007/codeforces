from sys import setrecursionlimit
setrecursionlimit(30000)
def cycle(f):
    v = f
    cyc[v] = True
    v = p[v]
    while v != f:
        cyc[v] = True
        v = p[v]



def dfs(v, par):
    global c, p, cycleroot
    if c[v] == 2:
        return
    p[v] = par
    if c[v] == 1:
        cycle(v)
        cycleroot = v
        return True
    c[v] = 1
    for u in graph[v]:
        if u != par:
            if dfs(u, v):
                return True
    c[v] = 2
    return False

def dfs1(v, d):
    if used[v]:
        return
    used[v] = True
    if cyc[v]:
        dist[v] = 0
    else:
        dist[v] = d
    for u in graph[v]:
        dfs1(u, dist[v] + 1)



n = int(input())
m = n
graph = [[] for i in range(n)]
p = [-1] * n
c = [0] * n
cyc = [False] * n
if m != n:
    print('NO')
    exit(0)
for i in range(m):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    graph[a].append(b)
    graph[b].append(a)
dfs(0, -1)
used = [False] * n
dist = [-1] * n
dfs1(cycleroot, 0)
print(' '.join([str(i) for i in dist]))
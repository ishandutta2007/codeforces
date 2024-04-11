def cycle(f):
    v = f
    cyc[v] = True
    v = p[v]
    while v != f:
        cyc[v] = True
        v = p[v]



def dfs(v, par):
    global c, p
    if c[v] == 2:
        return
    p[v] = par
    if c[v] == 1:
        cycle(v)
        return True
    c[v] = 1
    for u in graph[v]:
        if u != par:
            if dfs(u, v):
                return True
    c[v] = 2
    return False

def dfs1(v):
    if used[v]:
        return
    used[v] = True
    for u in graph[v]:
        dfs1(u)


n, m = map(int, input().split())
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
cnt = 0
for i in range(n):
    if cyc[i]:
        cnt += 1
dfs1(0)
for i in range(n):
    if not used[i]:
        print('NO')
        exit(0)
if cnt >= 3:
    print('FHTAGN!')
else:
    print('NO')
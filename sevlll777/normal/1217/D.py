n, m = map(int, input().split())
numedge = {}
graph = {}
for v in range(1, n + 1):
    graph[v] = set()
for i in range(m):
    a, b = map(int, input().split())
    numedge[(a, b)] = i
    graph[a].add(b)
visit = {}
par = {}
s, f = -1, -1


def dfs(v):
    global s, f
    visit[v] = 1
    for u in graph[v]:
        if u not in visit:
            par[u] = v
            dfs(u)
        elif visit[u] == 1:
            s = u
            f = v
            break
    visit[v] = -1


for v in graph:
    dfs(v)
if s == f == -1:
    print(1)
    print('1 ' * m)
else:
    print(2)
    ans = [0] * m
    for x in graph:
        for y in graph[x]:
            ans[numedge[(x, y)]] = (x > y) + 1
    print(*ans)
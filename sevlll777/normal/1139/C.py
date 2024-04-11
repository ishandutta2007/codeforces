from sys import setrecursionlimit
setrecursionlimit(10 ** 7)


def BFC(digraph, v, oboid):
    s2 = set()
    s1 = set()
    s1.add(v)
    cnt = 0
    while s1 != set():
        for element in s1:
            if element not in oboid:
                oboid.add(element)
                cnt += 1
                for key in digraph[element]:
                    s2.add(key)
        s1 = s2
        s2 = set()
    return cnt


n, k = map(int, input().split())
MOD = 10 ** 9 + 7
graph = {i: set() for i in range(1, n + 1)}
D = []
for i in range(n - 1):
    u, v, x = map(int, input().split())
    if x == 0:
        graph[u].add(v)
        graph[v].add(u)
wo = len(graph)
oboid = set()
comps = 0
ansq = 0
for v in graph:
    if v not in oboid:
        cnt = BFC(graph, v, oboid)
        ansq += pow(cnt, k, MOD)
        ansq %= MOD
print((pow(n, k, MOD) - ansq) % MOD)
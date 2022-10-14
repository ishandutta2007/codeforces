n, k = map(int, input().split())
graph = {i: set() for i in range(1, n + 1)}
for _ in range(k):
    u, v = map(int, input().split())
    graph[u].add(v)
    graph[v].add(u)
ans = 0
used = [0] * (n + 1)
for v in range(1, n + 1):
    if used[v] == 0:
        ans += 1
        S = [v]
        while S:
            ver = S.pop()
            for u in graph[ver]:
                if used[u] == 0:
                    S.append(u)
                    used[u] = 1
print(k - n + ans)
def path(s):
    s1= {s}
    s2 = set()
    used = [0] * (n + 1)
    used[s] = 1
    ans = 0
    while s1:
        ans += 1
        for v in s1:
            for u in graph[v]:
                if used[u] == 0:
                    paths[s][u] = ans
                    used[u] = 1
                    s2.add(u)
        s1 = s2
        s2 = set()


n = int(input())
A = [list(map(int, input())) for _ in range(n)]
graph = {i: set() for i in range(1, n + 1)}
for i in range(n):
    for j in range(n):
        if A[i][j]:
           graph[i + 1].add(j + 1)
m = int(input())
P = list(map(int, input().split()))
paths = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    path(i)
u = 0
v = P[0]
ans = []
while u < m - 1:
    ans.append(P[u])
    l = u
    r = min(m, u + n + 1)
    while r - l > 1:
        mid = (l + r) // 2
        if paths[P[u]][P[mid]] == mid - u:
            l = mid
        else:
            r = mid
    u = l
ans.append(P[-1])
print(len(ans))
print(*ans)
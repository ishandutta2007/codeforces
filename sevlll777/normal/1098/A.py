from collections import deque
n = int(input())
graph = {i: set() for i in range(1, n + 1)}
P = list(map(int, input().split()))
S = [0] + list(map(int, input().split()))
for i in range(n - 1):
    graph[P[i]].add(i + 2)
Q = deque([1])
used = [0] * (n + 1)
ans = S[1]
kek = {1: S[1]}
used[1] = 1
while Q:
    v = Q.popleft()
    for u in graph[v]:
        if used[u] == 0:
            used[u] = 1
            Q.append(u)
            if S[u] != -1:
                if kek[v] > S[u]:
                    print(-1)
                    exit(0)
                ans += (S[u] - kek[v])
                kek[u] = S[u]
            else:
                sos = set()
                for u2 in graph[u]:
                    sos.add(S[u2])
                if sos:
                    x = min(sos)
                    if kek[v] <= x:
                        ans += (x - kek[v])
                        kek[u] = x
                    else:
                        print(-1)
                        exit(0)
print(ans)
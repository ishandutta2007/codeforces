n = int(input())
P = [0, 0] + list(map(int, input().split()))
deep = [0] * (n + 1)
sons = []
for _ in range(n + 1):
    sons.append(set())
for i in range(2, n + 1):
    sons[P[i]].add(i)
cnt = 1
s1 = {1}
s2 = set()
while s1:
    for v in s1:
        for u in sons[v]:
            s2.add(u)
            deep[u] = cnt
    s1 = s2
    s2 = set()
    cnt += 1
J = dict()
ans = 0
for i in deep:
    if i not in J:
        J[i] = 0
    J[i] += 1
for a in J:
    ans += J[a] % 2
print(ans + 1)
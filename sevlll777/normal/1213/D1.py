n, k = map(int, input().split())
A = list(map(int, input().split()))
G = []
for _ in range(2 * 10 ** 5 + 100):
    G.append([])
c = 0
for i in A:
    if len(G[i]) < k:
        G[i].append(0)
while True:
    c += 1
    f = True
    for i in range(n):
        if A[i]:
            A[i] //= 2
            if len(G[A[i]]) < k:
                G[A[i]].append(c)
        if A[i]:
            f = False
    if f:
        break
ans = 10 ** 9
for t in G:
    if len(t) == k:
        ans = min(ans, sum(t))
print(ans)
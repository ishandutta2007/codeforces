n = int(input())
A = list(map(int, input().split()))
g = {}
for i in A:
    if i not in g:
        g[i] = 0
    g[i] += 1
m = int(input())
B = list(map(int, input().split()))
C = list(map(int, input().split()))
sas = [0, 0, 0]
for i in range(m):
    if B[i] not in g:
        g[B[i]] = 0
    if C[i] not in g:
        g[C[i]] = 0
    lol = [g[B[i]], g[C[i]], i + 1]
    sas = max(sas, lol)
print(sas[2])
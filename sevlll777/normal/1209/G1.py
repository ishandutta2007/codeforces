n, q = map(int, input().split())
A = list(map(int, input().split()))
left = {}
right = {}
for i in range(n):
    if A[i] not in left:
        left[A[i]] = i
    right[A[i]] = i
E = []
for elem in left:
    E.append([left[elem], -1])
    E.append([right[elem], 1])
E.sort()
u = 0
b = 0
cntr = {}
ans = 0
for i in range(n):
    while u < len(E) and E[u][0] == i:
        b -= E[u][1]
        u += 1
    if A[i] not in cntr:
        cntr[A[i]] = 0
    cntr[A[i]] += 1
    if b == 0:
        s = 0
        m = 0
        for iss in cntr:
            s += cntr[iss]
            m = max(m, cntr[iss])
        ans += s - m
        cntr = {}
print(ans)
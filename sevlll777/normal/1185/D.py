n = int(input())
A = list(map(int, input().split()))
if n == 2:
    print(1)
    exit(0)
elif n == 3:
    print(1)
    exit(0)
M = []
for i in range(n):
    A[i] = [A[i], i + 1]
A.sort()
for i in range(n - 1):
    M.append(A[i + 1][0] - A[i][0])
if len(set(M[1:])) == 1:
    print(A[0][1])
    exit(0)
if len(set(M[:-1])) == 1:
    print(A[-1][1])
    exit(0)
g = {}
for i in M:
    if i not in g:
        g[i] = 0
    g[i] += 1
for k in g:
    if g[k] >= n - 3:
        q = []
        for j in range(n - 1):
            if M[j] != k:
                q.append([M[j], j])
        if len(q) == 1:
            if q[0][0] == 0:
                print(A[q[0][1]][1])
                exit(0)
        if len(q) == 2:
            a, b = q[0], q[1]
            if a[0] + b[0] == k:
                if abs(a[1] - b[1]) == 1:
                    print(A[a[1] + 1][1])
                    exit(0)
print(-1)
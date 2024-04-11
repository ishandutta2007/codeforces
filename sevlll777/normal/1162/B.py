n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]
B = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if A[i][j] > B[i][j]:
            A[i][j], B[i][j] = B[i][j], A[i][j]
ans = "Possible"
for c in A:
    if c != sorted(c) or len(set(c)) != m:
        ans = "Impossible"
for c in B:
    if c != sorted(c) or len(set(c)) != m:
        ans = "Impossible"
for j in range(m):
    ddd = []
    d2 = []
    for i in range(n):
        ddd.append(A[i][j])
        d2.append(B[i][j])
    if ddd != sorted(ddd) or len(set(ddd)) != n or len(set(d2)) != n or d2 != sorted(d2):
        ans = "Impossible"
print(ans)
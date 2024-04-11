n = int(input())
A = list(map(int, input().split()))
q = []
fl = A[0]
cnt = 0
ans = 1
for i in range(1, n):
    if A[i] == fl:
        cnt += 1
    else:
        q.append(cnt)
        cnt = 1
        fl = A[i]
q.append(cnt)
for u in range(len(q) - 1):
    ans = max(ans, min(q[u], q[u + 1]))
print(ans * 2)
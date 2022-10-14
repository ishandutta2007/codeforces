n, m = map(int, input().split())
p = []
ans = 0
for i in range(n):
    p.append(input())
A = list(map(int, input().split()))
for j in range(m):
    h = []
    for i in range(n):
        h.append(p[i][j])
    ans += A[j] * max(h.count('A'), h.count('B'), h.count('C'), h.count('D'), h.count('E'))
print(ans)
n, k = map(int, input().split())
A = list(map(int, input().split()))
T = list(map(int, input().split()))
s = sum(A[:k])
ok = 0
for i in range(n):
    if T[i]:
        ok += A[i]
s_1 = 0
for i in range(k):
    if T[i]:
        s_1 += A[i]
ans = 0
for start in range(k, n):
    ans = max(ans, s - s_1)
    s -= A[start - k]
    s += A[start]
    if T[start - k]:
        s_1 -= A[start - k]
    if T[start]:
        s_1 += A[start]
ans = max(ans, s - s_1)
print(ans + ok)
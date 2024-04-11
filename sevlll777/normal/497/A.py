n, m = map(int, input().split())
A = [list(input()) for _ in range(n)]
ans = m
lc = [""] * n
for i in range(m):
    s = ''
    for j in range(n):
        s += A[j][i]
    srtd = True
    for x in range(1, len(s)):
        if s[x] < s[x - 1] and lc[x] == lc[x - 1]:
            srtd = False
    if srtd:
        ans -= 1
        for j in range(n):
            lc[j] += s[j]
print(ans)
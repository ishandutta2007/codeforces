n, m = map(int, input().split())
if n < m:
    n, m = m, n
ans = 0
while n >= 2  and m >= 1:
    ans += 1
    n -= 2
    m -= 1
    if n < m:
        n, m = m, n
print(ans)
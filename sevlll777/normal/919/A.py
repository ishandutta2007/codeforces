n, m = map(int, input().split())
ans = 1000000000
for i in range(n):
    a, b = map(int, input().split())
    ans = min(ans, a/b)
print(m * ans)
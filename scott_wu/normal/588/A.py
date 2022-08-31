n = int(input())
ans, cscore = 0, 1000000

for i in range(n):
    a, b = map(int, input().split())
    cscore = min(cscore, b)
    ans += a * cscore
print(ans)
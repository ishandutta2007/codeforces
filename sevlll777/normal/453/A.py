m, n = map(int, input().split())
ans = 0
for j in range(m, 0, -1):
    ans += j * (1 - ((j - 1) / j) ** n) * (j / m) ** n
print(ans)
n = int(input())
ans = "NO"
for i in range(2, n - 1):
    if i % 2 == 0 and (n - i) % 2 == 0:
        ans = "YES"
        break
print(ans)
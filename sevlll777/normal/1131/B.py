n = int(input())
ma = -1
ans = 0
la, lb = -1, -1
for _ in range(n):
    a, b = map(int, input().split())
    if [a, b] != [la, lb]:
        ans += max(0, min(a, b) - ma + 1 - (la == lb))
        ma = max(a, b)
        la, lb = a, b
print(ans)
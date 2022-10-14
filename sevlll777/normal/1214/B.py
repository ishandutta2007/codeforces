b = int(input())
g = int(input())
n = int(input())
ans = 0
for x in range(b + 1):
    y = n - x
    if g >= y >= 0:
        ans += 1
print(ans)
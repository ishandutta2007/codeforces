n, k = map(int, raw_input().split())

a = map(int, raw_input().split())

ans = k

for x in a:
    if k % x == 0:
        ans = min(ans, k / x)

print(ans)
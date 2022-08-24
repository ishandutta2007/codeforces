n, x = map (int, raw_input().split())
arr = map (int, raw_input().split())

ans = 0
for i in range(x):
    if i not in arr:
        ans += 1
if x in arr:
    ans += 1

print ans
n = int(raw_input())

arr = map(int, raw_input().split())

ans = 1
for x in sorted(arr):
    if ans <= x:
        ans += 1
print ans
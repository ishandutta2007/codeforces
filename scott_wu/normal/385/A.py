n, c = (int(s) for s in raw_input().split())
arr = map (int, raw_input().split())

best = 0
for i in range(n-1):
    best = max (best, arr[i] - arr[i+1] - c)

print best
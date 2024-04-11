n = int(input())
a = list(map(int, input().split())) + [0]
cur = 0
minx = 0
for i in range(n):
    cur += a[i - 1] - a[i]
    if cur < minx:
        minx = cur
print(-minx)
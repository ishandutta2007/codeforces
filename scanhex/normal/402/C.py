t = int(input())
for ignored in range(t):
    n, p = list(map(int, input().split()))
    a = [[False] * n for i in range(n)]
    cnt = [0] * n
    for i in range(2 * n + p):
        mini = float('inf')
        minim = float('inf')
        x, y = -1, -1
        for x1 in range(n):
            for y1 in range(x1 + 1, n):
                if x1 != y1 and not a[x1][y1] and (max(cnt[x1], cnt[y1]) < mini or max(cnt[x1], cnt[y1]) == mini and min(cnt[x1], cnt[y1]) < minim):
                    x, y = x1, y1
                    mini = max(cnt[x1], cnt[y1])
                    minim = min(cnt[x1], cnt[y1])
        cnt[x] += 1
        cnt[y] += 1
        a[x][y] = True
        a[y][x] = True
        print(x + 1, y + 1)
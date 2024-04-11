a = list(map(int, input().split()))
b = list(map(int, input().split()))
x1 = min(a[0], a[2], a[4], a[6])
x2 = max(a[0], a[2], a[4], a[6])
y1 = min(a[1], a[3], a[5], a[7])
y2 = max(a[1], a[3], a[5], a[7])
d1 = min(b[0] - b[1], b[2] - b[3], b[4] - b[5], b[6] - b[7])
d2 = max(b[0] - b[1], b[2] - b[3], b[4] - b[5], b[6] - b[7])
s1 = min(b[0] + b[1], b[2] + b[3], b[4] + b[5], b[6] + b[7])
s2 = max(b[0] + b[1], b[2] + b[3], b[4] + b[5], b[6] + b[7])
for x in range(-100, 101):
    for y in range(-100, 101):
        d = x - y
        s = x + y
        if x1 <= x <= x2 and y1 <= y <= y2 and s1 <= s <= s2 and d1 <= d <= d2:
            print("YES")
            exit(0)
print("NO")
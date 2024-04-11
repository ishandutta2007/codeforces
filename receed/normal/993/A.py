a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
x1 = sorted([a[0], a[2], a[4], a[6]])
y1 = sorted([a[1], a[3], a[5], a[7]])
x2 = sorted([b[0], b[2], b[4], b[6]])
y2 = sorted([b[1], b[3], b[5], b[7]])
ans = 'NO'
for i in range(x1[0], x1[3] + 1):
    for j in range(y1[0], y1[3] + 1):
        if x2[0] + y2[1] <= i + j <= x2[3] + y2[1] and y2[0] - x2[1] <= j - i <= y2[3] - x2[1]:
            ans = 'YES'
print(ans)
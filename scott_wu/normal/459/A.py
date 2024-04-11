x1, y1, x2, y2 = map(int, input().split())

if x1 == x2:
    x3 = x1 + y1 - y2
    print(x3, y1, x3, y2)
elif y1 == y2:
    y3 = y1 + x1 - x2
    print(x1, y3, x2, y3)
elif abs(x1-x2) == abs(y1-y2):
    print(x2, y1, x1, y2)
else:
    print(-1)
x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())
x5, y5, x6, y6 = map(int, input().split())
for x in range(x1 * 2, x2 * 2 + 1):
    x /= 2
    p1 = (x, y1)
    p2 = (x, y2)
    for x7, y7 in [p1, p2]:
        if (x3 <= x7 <= x4 and y3 <= y7 <= y4) or (x5 <= x7 <= x6 and y5 <= y7 <= y6):
            pass
        else:
            print('YES')
            #print(x7, y7)
            exit(0)
for y in range(y1 * 2, y2 * 2 + 1):
    y /= 2
    p1 = (x1, y)
    p2 = (x2, y)
    for x7, y7 in [p1, p2]:
        if (x3 <= x7 <= x4 and y3 <= y7 <= y4) or (x5 <= x7 <= x6 and y5 <= y7 <= y6):
            pass
        else:
            print('YES')
            #print(x7, y7)
            exit(0)
print('NO')
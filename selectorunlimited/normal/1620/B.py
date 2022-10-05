t = int(input())

for i in range(t):
    w, h = [int(x) for x in input().split()]
    x1 = [int(x) for x in input().split()]
    x2 = [int(x) for x in input().split()]
    y1 = [int(x) for x in input().split()]
    y2 = [int(x) for x in input().split()]
    x1.pop(0)
    x2.pop(0)
    y1.pop(0)
    y2.pop(0)
    x1.sort()
    x2.sort()
    y1.sort()
    y2.sort()
    if x1[-1] - x1[0] < x2[-1] - x2[0]:
        x1, x2 = x2, x1
    if y1[-1] - y1[0] < y2[-1] - y2[0]:
        y1, y2 = y2, y1
    print(max(h * (x1[-1] - x1[0]), w * (y1[-1] - y1[0])))
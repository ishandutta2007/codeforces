from math import ceil
r, x1, y1, x2, y2 = map(int, input().split())
d = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5
print(ceil(d / (2 * r)))
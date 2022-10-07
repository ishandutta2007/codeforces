n = input()
points = [[int(_) for _ in raw_input().split()] for __ in range(n)]
x, y = zip(*points)
xsize, ysize = max(x) - min(x) + 1, max(y) - min(y) + 1
print (max(xsize, ysize) - 1) ** 2
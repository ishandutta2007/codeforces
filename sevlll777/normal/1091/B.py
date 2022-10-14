n = int(input())
mas1 = [float('-inf'), float('-inf')]
min1 = [float('inf'), float('inf')]
for t in range(n):
    x1, y1 = map(int, input().split())
    mas1 = max(mas1, [x1,y1])
for t in range(n):
    x1, y1 = map(int, input().split())
    min1 = min(min1, [x1, y1])
print(mas1[0]+min1[0], mas1[1]+min1[1])
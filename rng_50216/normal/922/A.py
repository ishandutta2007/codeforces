x, y = map(int, input().split())
if (x + y) % 2 == 0 or y == 0 or x < y - 1 or (x + y > 1 and y < 2):
    print('No')
else:
    print('Yes')
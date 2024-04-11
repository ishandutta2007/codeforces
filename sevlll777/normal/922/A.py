x, y = map(int, input().split())
if x >= 1 and y == 1 or y == 0:
    print('No')
    exit(0)
if x % 2 != y % 2 and x + 1 >= y:
    print('Yes')
else:
    print('No')
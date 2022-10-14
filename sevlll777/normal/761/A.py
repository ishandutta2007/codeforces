a, b = map(int, input().split())
if abs(a - b) <= 1 and (a or b):
    print('YES')
else:
    print('NO')
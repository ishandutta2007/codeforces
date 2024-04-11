for _ in range(int(input())):
    x, y = map(int, input().split())
    s = x - y
    if s == 1:
        print('NO')
    else:
        print('YES')
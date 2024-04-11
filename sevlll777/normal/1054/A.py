x, y, z, t1, t2, t3 = map(int, input().split())
v1 = abs(x - y) * t1
v2 = abs(x - z) * t2 + t3 + abs(x - y) * t2 + t3 + t3
if v1 >= v2:
    print('YES')
else:
    print('NO')
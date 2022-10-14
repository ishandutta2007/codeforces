a, b, c = map(int, input().split())
if (a + b + c) % 2:
    print('Impossible')
    exit(0)
z = (a + b + c) // 2
if z >= max(a, b, c) and z > sorted([a, b, c])[1]:
    print(z - c, z - a, z - b)
else:
    print('Impossible')
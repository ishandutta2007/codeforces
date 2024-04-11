a, b = map(int, input().split())
a, b = min(a, b), max(a, b)
for x in range(1, a):
    if ((a ** 2 - x ** 2) ** 0.5) % 1 < 10 ** -5:
        y = round((a ** 2 - x ** 2) ** 0.5)
        if x > 0 and y > 0 and (y * b) % a == 0 and (x * b) % a == 0:
            print('YES')
            print(0, 0)
            print(x, y)
            print(y * b // a, -x * b // a)
            exit(0)
print('NO')
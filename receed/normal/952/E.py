n = int(input())
x = y = 0
for i in range(n):
    s, t = input().split()
    if t == 'soft':
        x += 1
    else:
        y += 1
if x < y:
    x, y = y, x
for i in range(1, 200):
    if (i ** 2 + 1) // 2 >= x and i ** 2 // 2 >= y:
        print(i)
        break
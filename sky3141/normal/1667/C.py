n = int(input())

a = (n + 1) // 3
b = n - a
print(b)

if n == 1:
    print(1, 1)
    exit()

r, c = b, b
for _ in range(a):
    print(r, c)
    r -= 2
    c -= 1
r, c = b - 1, b - a
for _ in range(a - 1):
    print(r, c)
    r -= 2
    c -= 1
for i in range(1, b - 2 * a + 1 + 1):
    print(i, i)
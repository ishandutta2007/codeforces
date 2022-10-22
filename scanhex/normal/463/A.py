n, s = map(int, input().split())
maxx = -1
for i in range(n):
    a, b = map(int, input().split())
    if 100 * a + b <= 100 * s and (100 - b) % 100 > maxx:
        maxx = (100 - b) % 100
print(maxx)
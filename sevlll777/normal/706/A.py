a, b = map(int, input().split())
t = 10 ** 9
n = int(input())
for _ in range(n):
    x, y, v = map(int, input().split())
    t = min(((x - a) ** 2 + (y - b) ** 2) ** 0.5 / v, t)
print(t)
r, d = map(int, raw_input().split())

n = input()

ans = 0
for i in range(n):
    x, y, c = map(int, raw_input().split())
    if x * x + y * y > c * c:
        if x * x + y * y >= (r - d + c) * (r - d + c):
            if x * x + y * y <= (r - c) * (r - c):
                ans += 1
print ans
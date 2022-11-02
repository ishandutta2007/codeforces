k, b, n, t = map(int, raw_input().split())
ans = n + 1
z = 1
while t >= z and ans > 0:
    ans -= 1
    z = k*z + b

print ans
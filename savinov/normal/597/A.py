k, a, b = map(int, raw_input().split())

if b < 0:
    a, b = -b, -a
ans = 0
if a < 0:
    ans += (-a) // k
    a = 0
if a == 0:
    ans += 1
    a = 1
ans += b // k - (a - 1) // k

print ans
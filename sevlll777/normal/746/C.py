s, x1, x2 = map(int, input().split())
t1, t2 = map(int, input().split())
p, d = map(int, input().split())
v1 = t2 * abs(x1 - x2)
v2 = 0
if d == 1 and p <= x1:
    v2 = x1 - p
elif d == 1:
    v2 = s - p + s - x1
    d=-d
elif p >= x1:
    v2 = p - x1
else:
    v2 = p + x1
    d=-d
p, x1 = x1, x2
if d == 1 and p <= x1:
    v2 += x1 - p
elif d == 1:
    v2 += s - p + s - x1
elif p >= x1:
    v2 += p - x1
else:
    v2 += p + x1
v2 *= t1
print(min(v1, v2))
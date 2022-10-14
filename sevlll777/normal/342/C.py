r, h = map(int, input().split())
k = (h // r) * 2
d = h % r
if d >= 2 * r / 3 + 1:
    k += 3
elif d >= r / 2:
    k += 2
else:
    k += 1
print(k)
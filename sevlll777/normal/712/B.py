s = input()
if len(s) % 2:
    print(-1)
    exit(0)
l, r, u, d = 0, 0, 0, 0
for i in s:
    if i == 'L':
        l += 1
    elif i == 'R':
        r += 1
    elif i == 'U':
        u += 1
    else:
        d += 1
x = abs(r - l)
y = abs(d - u)
print((x + y) // 2)
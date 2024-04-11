a, b = input().split(':')
a = list(a)
b = list(b)
c = 10
for i in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
    for j in range(len(a)):
        if a[j] == i:
            a[j] = c
    for j in range(len(b)):
        if b[j] == i:
            b[j] = c
    c += 1
a = list(map(int, a))
b = list(map(int, b))
ans = []
for c in range(2, 200):
    x1 = 0
    x2 = 0
    for p in range(len(a)):
        x1 += a[p] * c ** (len(a) - p - 1)
    for p in range(len(b)):
        x2 += b[p] * c ** (len(b) - p - 1)
    if 0 <= x1 <= 23 and 0 <= x2 <= 59 and max(a) < c and max(b) < c:
        ans.append(c)
if len(ans) > 100:
    print(-1)
elif ans:
    print(*ans)
else:
    print(0)
x, y, l, r = map(int, input().split())

xs = []
now = 1
while True:
    if now > r:
        break
    xs.append(now)
    now *= x

ys = []
now = 1
while True:
    if now > r:
        break
    ys.append(now)
    now *= y

ress = [x + y for x in xs for y in ys]
ress = [i for i in ress if l <= i <= r]
ress.append(l - 1)
ress.append(r + 1)
ress = list(set(ress))
ress = sorted(ress)

lst = -1
ans = 0
for i in ress:
    if lst != -1:
        ans = max(ans, i - lst - 1)
    lst = i

print(ans)
n = int(raw_input())

a, b = 0, 0
good = False
for i in range(n):
    x, y = (int(s) for s in raw_input().split())
    a += x
    b += y
    if (x + y) % 2 == 1:
        good = True

if (a + b) % 2 == 1:
    print -1
elif a % 2 == 1:
    print 1 if good else -1
else:
    print 0
x, s = map(int, input().split())
if x > s:
    print(-1)
    exit(0)
if x == s == 0:
    print(0)
    exit(0)
if x == s:
    print(1)
    print(x)
    exit(0)

if x == 0 and s % 2 == 1:
    print(-1)
    exit(0)
elif x == 0:
    print(2)
    print(s // 2, s // 2)
    exit(0)
if (s + x) % 2 == 1:
    print(-1)
    exit(0)
lol = (s - x) // 2
if lol ^ (s - lol) == x:
    print(2)
    print(lol, s - lol)
    exit(0)
print(3)
print(lol, lol, x)
def fair(a, b, c):
    if a > b:
        x = a
        a = b
        b = x
    if c + a < b:
        return c + a
    return b + (c - (b - a)) // 2

q = int(input())

for _ in range(q):
    x = input().split()
    x = [int(t) for t in x]
    a = x[0]
    b = x[1]
    c = x[2]
    ans = 0
    ans = max(ans, fair(a, b, c))
    ans = max(ans, fair(a, c, b))
    ans = max(ans, fair(b, c, a))
    print(ans)
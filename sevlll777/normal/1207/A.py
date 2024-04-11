for _ in range(int(input())):
    b, p, f = map(int, input().split())
    h, c = map(int, input().split())
    b //= 2
    if h > c:
        if b < p:
            print(h * b)
        else:
            b -= p
            print(h * p + min(b, f) * c)
    else:
        if b < f:
            print(c * b)
        else:
            b -= f
            print(f * c + min(b, p) * h)
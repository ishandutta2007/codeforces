for _ in range(int(input())):
    l, r, d = map(int, input().split())
    l, r = min(l, r), max(l, r)
    if d < l or d > r:
        print(d)
    else:
        print(r + d - r % d)
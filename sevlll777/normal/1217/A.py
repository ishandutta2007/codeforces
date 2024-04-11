for _ in range(int(input())):
    ans = 0
    cnt = 0
    s, i, e = map(int, input().split())
    b = (s - i + e - 1) // 2
    if b < 0:
        print(0)
    elif b == 0:
        print(1)
    elif b >= e:
        print(e + 1)
    else:
        print(b + 1)
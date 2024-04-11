for _ in range(int(input())):
    a, b = map(int, input().split())
    if a == b:
        print(0)
    else:
        if a < b:
            if (b - a) % 2:
                print(1)
            else:
                print(2)
        else:
            if (b - a) % 2 == 0:
                print(1)
            else:
                print(2)
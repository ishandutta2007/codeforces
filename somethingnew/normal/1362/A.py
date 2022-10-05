for t in range(int(input())):
    a, b = map(int,input().split())
    a1 = 0
    b1 = 0
    while a % 2 == 0:
        a //= 2
        a1 += 1
    while b % 2 == 0:
        b //= 2
        b1 += 1
    if a != b:
        print(-1)
    else:
        print((abs(a1-b1) + 2) // 3)
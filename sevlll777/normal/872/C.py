for i in range(int(input())):
    x = int(input())
    if x <= 3 or x == 5 or x == 7 or x == 11:
        print(-1)
    elif x % 4 == 0:
        print(x // 4)
    elif x % 4 == 1:
        print((x - 9) // 4 + 1)
    elif x % 4 == 2:
        print((x - 6) // 4 + 1)
    else:
        print((x - 15) // 4 + 2)
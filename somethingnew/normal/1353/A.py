for i in range(int(input())):
    a,b = map(int, input().split())
    if a == 1:
        print(0)
    elif a == 2:
        print(b)
    else:
        print(b*2)
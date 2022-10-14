for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    c0 = a.count(0)
    c1 = n - c0
    if c0 >= (n+1)//2:
        print(c0)
        print('0 ' * c0)
    else:
        if c1 % 2:
            c1 -= 1
        print(c1)
        print('1 ' * c1)
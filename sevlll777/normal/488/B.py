n = int(input())
if n == 4:
    x1, x2, x3, x4 = int(input()), int(input()), int(input()), int(input())
    x1, x2, x3, x4 = sorted([x1, x2, x3, x4])
    if x4 == 3 * x1 and 4 * x1 == x2 + x3:
        print('YES')
    else:
        print('NO')
elif n == 0:
    print('YES\n1\n1\n3\n3')
else:
    if n == 1:
        a = int(input())
        print('YES')
        print(2 * a)
        print(2 * a)
        print(3 * a)
    elif n == 2:
        a, b = int(input()), int(input())
        a, b = sorted([a, b])
        if b == 3 * a:
            print('YES')
            print(2 * a)
            print(2 * a)
        elif 3 * a >= b:
            print('YES')
            print(3 * a)
            print(4 * a - b)
        elif (a + b) % 4 == 0:
            x1 = (a + b) // 4
            x4 = 3 * x1
            if x1 <= a <= x4 and x1 <= b <= x4:
                print('YES')
                print(x1)
                print(x4)
            else:
                if b % 3 == 0:
                    x1 = b // 3
                    x3 = b - a
                    a, x3 = min(a, x3), max(a, x3)
                    if x1 <= a <= x3 <= b:
                        print('YES')
                        print(x1)
                        print(x3)
                    else:
                        print('NO')
                else:
                    print('NO')
        else:
            if b % 3 == 0:
                x1 = b // 3
                x3 = b - a
                a, x3 = min(a, x3), max(a, x3)
                if x1 <= a <= x3 <= b:
                    print('YES')
                    print(x1)
                    print(x3)
                else:
                    print('NO')
            else:
                print('NO')
    else:
        a, b, c = int(input()), int(input()), int(input())
        a, b, c = sorted([a, b, c])
        if c % 3 == 0:
            x1 = c // 3
        else:
            x1 = 10 ** 9
        x2 = 4 * a - b
        x3 = 4 * a - b
        x4 = 3 * a
        if x1 <= a <= b <= c and 4 * x1 == a + b and c == 3 * x1:
            print('YES')
            print(x1)
        elif a <= x2 <= b <= c and c == 3 * a and 4 * a == x2 + b:
            print('YES')
            print(x2)
        elif a <= b <= x3 <= c and c == 3 * a and 4 * a == b + x3:
            print('YES')
            print(x3)
        elif c <= x4 and 4 * a == b + c and 3 * a == x4:
            print('YES')
            print(x4)
        else:
            print('NO')
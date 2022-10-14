for _ in range(int(input())):
    n = int(input())
    if n <= 10 ** 5 - 5:
        print('133' + '7' * n)
    else:
        cf = 300
        g = n - (cf + 2) * (cf + 1) // 2
        b = g // (cf * (cf - 1) // 2)
        c = g % (cf * (cf - 1) // 2)
        print('1' + '3' * cf + '7' * b + '1' * c + '337')
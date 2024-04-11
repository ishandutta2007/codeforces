for i in range(int(input())):
    num, n = map(int, input().split())
    if num < n * n:
        print('NO')
    elif num % 2 != n % 2:
        print('NO')
    else:
        print('YES')
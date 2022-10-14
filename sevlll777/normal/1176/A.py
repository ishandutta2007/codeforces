for i in range(int(input())):
    n = int(input()) 
    cnt = 0
    while n > 1:
        cnt += 1
        if n % 2 == 0:
            n //= 2
        elif n % 3 == 0:
            n = 2 * n // 3
        elif n % 5 == 0:
            n = 4 * n // 5
        else:
            cnt = -1
            break
    print(cnt)
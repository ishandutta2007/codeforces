a, b = map(int, input().split(':'))
cnt = 0
while True:
    if (str(a // 10) + str(a % 10) + str(b // 10) + str(b % 10)) != (str(a // 10) + str(a % 10) + str(b // 10) + str(b % 10)) [::-1]:
        if b != 59:
            b += 1
        else:
            if a != 23:
                a += 1
                b = 0
            else:
                print(cnt + 1)
                exit(0)
    else:
        print(cnt)
        exit(0)
    cnt += 1
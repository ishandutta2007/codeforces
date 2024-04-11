for t in range(int(input())):
    nm1, nm2 = map(int, input().split())
    if nm1 % 2 == 0:
        if nm1 - 2 * nm2 + 2 > 0:
            print('YES')
            ar = [2] * (nm2-1)
            print(nm1 - 2 * nm2 + 2, * ar)
            continue
    if nm1 - nm2 + 1 > 0 and (nm1 - nm2) % 2 == 0:
        print('YES')
        ar = [1] * (nm2-1)
        print(nm1-nm2+1, *ar)
        continue
    print('NO')
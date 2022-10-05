for i in range(int(input())):
    n = int(input())
    if n == 1:
        print(-1)
    else:
        l = n - 1
        if l % 3:
            print(l * '2' + '3')
        else:
            print('4' + (l - 1) * '2' + '3')
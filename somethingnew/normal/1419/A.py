def solve():
    n = int(input())
    lst = [int(i) for i in list(input())]
    if n % 2:
        for i in range(0, n, 2):
            if lst[i] % 2 == 1:
                print(1)
                return 0
        print(2)
    else:
        for i in range(1, n, 2):
            if lst[i] % 2 == 0:
                print(2)
                return 0
        print(1)
for i in range(int(input())):
    solve()
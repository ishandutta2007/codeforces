def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    if n == 1:
        if lst[0] % 2:
            print(-1)
        else:
            print(1)
            print(1)
    else:
        if lst[0] % 2 == 0:
            print(1)
            print(1)
        elif lst[1] % 2 == 0:
            print(1)
            print(2)
        else:
            print(2)
            print(1, 2)
for i in range(int(input())): solve()
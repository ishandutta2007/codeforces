def solve():
    n = int(input())
    if n % 3 == 0:
        print(n//3,0,0)
        return 0
    if n % 3 == 1:
        if n < 7:
            print(-1)
        else:
            print((n-7)//3, 0, 1)
        return 0
    if n < 5:
        print(-1)
        return 0
    print((n-5)//3, 1, 0)
for i in range(int(input())):
    solve()
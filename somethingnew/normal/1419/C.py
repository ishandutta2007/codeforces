def solve():
    n, x = map(int,input().split())
    lst = list(map(int,input().split()))
    sum = 0
    b = 0
    for i in lst:
        if i == x:
            b += 1
        sum += i
    if b == n:
        print(0)
        return 0
    if b >= 1:
        print(1)
        return 0
    if sum == x * n:
        print(1)
        return 0
    print(2)
for i in range(int(input())):
    solve()
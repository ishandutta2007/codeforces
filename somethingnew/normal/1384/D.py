def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    k = 1
    while k < 10**9:
        k *= 2
    num = 0
    while k and num % 2 == 0:
        num = 0
        for i in lst:
            if i % (k * 2) // k == 1:
                num += 1
        k //= 2
    if k == 0 and num % 2 == 0:
        print("DRAW")
        return 0
    if (num % 4 == 1) or (n % 2 == 0):
        print("WIN")
    else:
        print("LOSE")
for i in range(int(input())):
    solve()
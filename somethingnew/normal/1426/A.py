def solve():
    n, x = map(int,input().split())
    if n <= 2:
        print(1)
    else:
        print((n - 3 + x) // x + 1)
for i in range(int(input())):
    solve()
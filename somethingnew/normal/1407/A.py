def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    if sum(lst) <= n // 2:
        print(n//2)
        print("0 " * (n // 2))
    else:
        print(n//2 + (n // 2) % 2)
        print("1 " * (n//2 + (n // 2) % 2))
for i in range(int(input())):
    solve()
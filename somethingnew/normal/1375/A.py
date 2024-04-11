def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    for i in range(n):
        if i % 2 == 0:
            print(abs(lst[i]), end =' ')
        else:
            print(-abs(lst[i]), end=' ')
    print()
for i in range(int(input())):
    solve()
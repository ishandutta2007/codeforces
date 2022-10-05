def solve():
    n = int(input())
    lst = list(map(int, input().split()))
    for i in range(n):
        k = 1
        while k <= lst[i]:
            k *= 2
        k //= 2
        lst[i] = k
    print(*lst)
for i in range(int(input())):
    solve()
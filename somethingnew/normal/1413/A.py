def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    la = [0 for i in range(n)]
    for i in range(n):
        if i % 2 == 0:
            la[i] = lst[i^1]
        else:
            la[i] = - lst[i^1]
    print(*la)
for i in range(int(input())):
    solve()
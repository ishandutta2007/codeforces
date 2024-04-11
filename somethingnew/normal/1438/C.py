def solve():
    n, m = map(int,input().split())
    lst = [list(map(int, input().split())) for i in range(n)]
    for i in range(n):
        for j in range(m):
            if (i + j + lst[i][j]) % 2:
                lst[i][j] += 1
    for i in lst:
        print(*i)
for i in range(int(input())):
    solve()
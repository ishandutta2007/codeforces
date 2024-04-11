def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    lst.reverse()
    ans = 0
    for i in range(1, n):
        if lst[i-1] < lst[i]:
            ans += lst[i] - lst[i-1]
    print(ans)
for i in range(int(input())):
    solve()
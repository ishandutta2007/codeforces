def solve():
    n, k = map(int,input().split())
    lst = list(map(int,input().split()))
    lst.sort()
    ans = 0
    for i in range(n - k - 1, n):
        ans += lst[i]
    print(ans)
for i in range(int(input())):
    solve()
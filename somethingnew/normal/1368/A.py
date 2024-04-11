def solve():
    a, b,n = map(int,input().split())
    a,b = min(a,b), max(a,b)
    ans = 0
    while b <= n:
        a += b
        a, b = min(a, b), max(a, b)
        ans += 1
    print(ans)
for i in range(int(input())):
    solve()
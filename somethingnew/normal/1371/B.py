def solve():
    n, k = map(int, input().split())
    if k < n:
        print(k * (k+1) // 2)
    else:
        ans = n * (n-1) // 2
        ans += 1
        print(ans)
for i in range(int(input())):
    solve()
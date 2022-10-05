def solve():
    a,b, n, m = map(int,input().split())
    mab = min(a,b)
    if mab < m:
        print("NO")
        return
    if a + b < n + m:
        print("NO")
        return
    print("YES")
for i in range(int(input())):
    solve()
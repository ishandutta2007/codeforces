def solve():
    n, m = map(int,input().split())
    if n % m == 0:
        print("YES")
    else:
        print("NO")
for i in range(int(input())):
    solve()
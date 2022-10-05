def solve():
    a,b,c,d = map(int,input().split())
    ans = b
    a -= b
    if a <= 0:
        print(b)
        return
    k = c - d
    if k <= 0:
        print(-1)
        return
    print(b + ((a + k - 1) // k) * c)
for i in range(int(input())):
    solve()
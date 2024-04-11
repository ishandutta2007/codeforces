def solve():
    n,x,m = map(int,input().split())
    ll = x
    rr = x
    for i in range(m):
        a,b = map(int,input().split())
        if a <= rr <= b:
            rr = b
        if a <= ll <= b:
            ll = a
    print(rr-ll+1)
for i in range(int(input())):
    solve()
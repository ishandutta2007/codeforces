def solve():
    a,b=map(int,input().split())
    k = b//2
    k2 = k * 2
    if k < a:
        print(-1, -1)
        return 0
    print(k,k2)
for i in range(int(input())):
    solve()
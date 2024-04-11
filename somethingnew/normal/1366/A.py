def solve():
    a, b = map(int,input().split())
    k = a + b
    k //= 3
    z = min(a,b)
    print(min(z,k))
for i in range(int(input())):
    solve()
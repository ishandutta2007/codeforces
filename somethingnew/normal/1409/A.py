def solve():
    a, b = map(int,input().split())
    c = abs(b - a)
    print((c + 9) // 10)
for i in range(int(input())):
    solve()
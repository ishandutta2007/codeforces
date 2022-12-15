def solve():
    n, x, a, b = [int(c) for c in input().split()]
    print(min(n - 1, abs(a - b) + x))

t = int(input())
for _ in range(t):
    solve()
def solve():
    n = input()
    print(int(n) % 10 * 10 + len(n) * (len(n) + 1) // 2 - 10)
for i in range(int(input())):
    solve()
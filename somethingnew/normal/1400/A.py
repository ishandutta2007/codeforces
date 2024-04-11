def solve():
    n = int(input())
    s = input()
    ans = ["?" for i in range(n)]
    for i in range(n):
        ans[i] = s[i + i]
    print(*ans, sep='')
for i in range(int(input())):
    solve()
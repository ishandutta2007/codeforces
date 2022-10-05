def solve():
    s = input()
    n = len(s)
    x = int(input())
    ans = ["0" for i in range(n)]
    for i in range(n):
        if s[i] == "1":
            if i >= 2 * x and s[i - 2 * x] == "1":
                ans[i - x] = "1"
            elif i >= x and i < 2 * x:
                ans[i - x] = "1"
            elif i + x < n:
                ans[i + x] = "1"
            else:
                print(-1)
                return
        else:
            if i - x >= 0 and ans[i-x] == "1":
                print(-1)
                return
    print(*ans,sep='')
for i in range(int(input())):
    solve()
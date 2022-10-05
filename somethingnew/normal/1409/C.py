def solve():
    n, x, y = map(int,input().split())
    a = [0 for i in range(n)]
    ans = [10000000, 0, 0]
    for i in range(1, 50):
        if (y - x) % i == 0 and (y - x) // i < n:
            yy = y // i
            xx = x // i
            pos = min(xx, n - (yy - xx) - 1)
            res = x + (n - pos - 1) * i
            if x - pos * i == 0:
                res += i
            if res < ans[0]:
                ans[0] = res
                ans[1] = x - pos * i
                if ans[1] == 0:
                    ans[1] += i
                ans[2] = i
    a[0] = ans[1]
    for i in range(1, n):
        a[i] = a[i-1] + ans[2]
    print(*a)
for i in range(int(input())):
    solve()
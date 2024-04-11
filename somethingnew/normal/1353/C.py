for t in range(int(input())):
    n = int(input())
    ans = 0
    sm = 0
    for i in range(1, n//2 + 2):
        w = (i * 2 - 1) ** 2
        w -= sm
        ans += w * (i-1)
        sm += w
    print(ans)
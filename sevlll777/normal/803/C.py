n, k = map(int, input().split())
if n < k * (k + 1) // 2:
    print(-1)
else:
    drd = 1
    for d in range(1, int(n ** 0.5) + 1):
        if n % d == 0:
            x = n // d
            if x >= k * (k + 1) // 2:
                drd = max(d, drd)
            if d >= k * (k + 1) // 2:
                drd = max(n // d, drd)
    ans = []
    x = n // drd
    x -= k * (k - 1) // 2
    for i in range(1, k):
        ans.append(i * drd)
    ans.append(x * drd)
    print(*ans)
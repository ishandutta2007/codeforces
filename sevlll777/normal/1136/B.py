n, k = map(int, input().split())
if n == k or k == 1:
    print(n + 4 + 2 * (n - 2))
    exit(0)
cnt = 3 * (min(k - 1, n - k)) + 1 + 2 * (max(k - 1, n - k) - 1) + 3 + n
print(cnt)
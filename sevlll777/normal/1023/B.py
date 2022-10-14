n, k = map(int, input().split())
if n + (n - 1) < k:
    print(0)
    exit(0)
print((k - 1) // 2 - max(0, k - n - 1))
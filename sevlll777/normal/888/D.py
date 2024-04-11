n, k = map(int, input().split())
if k == 1:
    print(1)
elif k == 2:
    print(1 + n * (n - 1) // 2)
elif k == 3:
    print(1 + n * (n - 1) * (n - 2) // 3 + n * (n - 1) // 2)
else:
    print(1 + n * (n - 1) // 2 + n * (n - 1) * (n - 2) // 3 + 3 * n * (n - 1) * (n - 2) * (n - 3) // 8)
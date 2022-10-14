n, m = map(int, input().split())
if m <= 1:
    print(1)
    exit(0)
print(min(m, n - m))
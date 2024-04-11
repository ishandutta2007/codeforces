n, k = [int(i) for i in input().split()]
a = n // 2 // (k + 1)
print(a, a * k, n - a * (k + 1))
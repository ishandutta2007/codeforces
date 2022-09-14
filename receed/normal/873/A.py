n, k, x = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
print(sum(a[:n - k]) + x * k)
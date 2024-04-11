n = int(input())
s = sum([i * (n - i) for i in range(n)])
print(n + s)
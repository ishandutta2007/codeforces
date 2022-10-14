from math import ceil
n, k = map(int, input().split())
id = list(map(int, input().split()))
x = ceil(((1 + 8 * k) ** 0.5 - 1) / 2)
sus = x * (x - 1) // 2
print(id[k - sus - 1])
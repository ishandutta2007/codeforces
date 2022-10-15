from math import floor
n = int(input())
q = floor(n ** 0.5)
print(2 * (q + (n + q - 1) // q))
def popcount(x):
  if x == 0:
    return 0
  return x % 2 + popcount(x / 2)

n, m, k = [int(_) for _ in raw_input().split()]
x = [input() for _ in range(m + 1)]

for i in range(m):
  x[i] = 1 if popcount(x[i] ^ x[-1]) <= k else 0

print sum(x[:-1])
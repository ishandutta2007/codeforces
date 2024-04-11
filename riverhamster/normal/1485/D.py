def inputs():
  return map(int, input().split())

n, m = inputs()
lcm = 720720

for i in range(n):
  a = list(inputs())
  for j in range(m):
    if (i ^ j) & 1: print(lcm, end=" ")
    else: print(lcm - a[j] ** 4, end=" ")
  print()
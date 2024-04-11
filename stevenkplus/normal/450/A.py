n, m = [int(_) for _ in raw_input().split()]
ar = [int(_) for _ in raw_input().split()]

cur = range(n)
while len(cur) > 1:
  guy, cur = cur[0], cur[1:]
  ar[guy] -= m
  if ar[guy] > 0:
    cur += [guy]

print cur[0] + 1
def go():
  n, m = [int(_) for _ in raw_input().split()]
  if n == 0: return 0
  if n < m: return -1
  x = (n - 1) // (2 * m)
  return (x + 1) * m


print go()